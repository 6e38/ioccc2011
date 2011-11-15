#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
int http_read_int(int sock)
{
   char buffer[11];
   int i = 0;
   int r = 0;
   while (i<sizeof(buffer)&&!(i>=2&&buffer[i-1]=='\n'&&buffer[i-2]=='\r')&&(r = read(sock, &buffer[i], 1))) { i++; }
   buffer[i] = '\0';
   //if (i==0||buffer[i-1]=='\r'||buffer[i-1]=='\n'||buffer[i-1]=='\0') return 0;
   //if (!isdigit(buffer[0])) { printf("buffer '%s'\n", buffer); return -1; }
   printf("chunk '%s'\n", buffer);
   return strtol(buffer, NULL, 16);
}
char *http_read_data(int sock, char *header)
{
   char *data = NULL;
   char *ptr = NULL;
   int len = 0;
   int l = 0;
   ptr = strstr(header, "Content-Length: ");
   if (ptr != NULL)
   {
      ptr += strlen("Content-length: ");
      len = atoi(ptr);
      if (len == 0) return NULL;
      data = malloc(len + 1);
      if (data == NULL) return NULL;
      l = read(sock, data, len);
      if (l != len) { free(data); return NULL; }
      data[l] = '\0';
   }
   else
   {
      char junk;
      char buffer[0x6e38];
      int i = 0;
      int r;
      printf("chunked\n"); // del
      while (len = http_read_int(sock))
      {
         printf("reading chunk %d\n", len);
         if (len == -1) return NULL;
         r = 0;
         while (r < len)
         {
            r += read(sock, &buffer[i+r], len - r);
            printf("read %d\n", r);
         }
         i += r;
         printf("i %d, r %d\n", i, r);
         read(sock, &junk, 1);
         read(sock, &junk, 1);
      }
      buffer[i] = '\0';
      data = malloc(i);
      if (data == NULL) return NULL;
      memcpy(data, buffer, i);
   }
   return data;
}
char *http_read_header(int sock)
{
   char *header = NULL;
   char buffer[1337];
   int i = 0;
   while (i<sizeof(buffer)&&!(i>=4&&buffer[i-1]=='\n'&&buffer[i-2]=='\r'&&buffer[i-3]=='\n'&&buffer[i-4]=='\r'))
   {
      read(sock, &buffer[i], 1);
      i++;
   }
   header = malloc(i);
   if (header == NULL) return NULL;
   memcpy(header, buffer, i);
   fprintf(stdout, header); // del
   fprintf(stdout, "Data:\n"); // del
   return header;
}
char *http_read_response(int sock)
{
   char *header = NULL;
   char *data = NULL;
   header = http_read_header(sock);
   if (header == NULL) return NULL;
   data = http_read_data(sock, header);
   free(header);
   if (data == NULL) return NULL;
   return data;
}
int http_open(char *hostname, unsigned short port)
{
   struct hostent *host;
   int sock = 0;
   struct sockaddr_in addr;
   host = gethostbyname(hostname);
   if (host == NULL) return 0;
   sock = socket(AF_INET, SOCK_STREAM, 0);
   if (sock == 0) return 0;
   addr.sin_family = AF_INET;
   addr.sin_addr.s_addr = *((unsigned int*)host->h_addr_list[0]);
   addr.sin_port = htons(port);
   if (connect(sock, (struct sockaddr*)&addr, sizeof(addr))) return 0;
   return sock;
}
char *http_get(char *hostname, char *path)
{
   char buffer[1337];
   int sock = 0;
   char *data = NULL;
   sock = http_open(hostname, 80);
   if (sock == 0) return NULL;
   sprintf(buffer, "GET %s HTTP/1.1\r\n", path);
   write(sock, buffer, strlen(buffer));
   sprintf(buffer, "Host: %s\r\n", hostname);
   write(sock, buffer, strlen(buffer));
   write(sock, "\r\n", 2);
   data = http_read_response(sock);
   close(sock);
   return data;
}
int main(int argc, char *argv[])
{
   char *data = NULL;
   //data = http_get("gaia.rose.hp.com", "/");
   data = http_get("thai-dl360.americas.hpqcorp.net", "/"); // chunked
   if (data == NULL) { fprintf(stderr, "err\n"); return 1; }
   fprintf(stdout, data);
   free(data);
   return 0;
}
