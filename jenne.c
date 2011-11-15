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
   return strtol(buffer, NULL, 16);
}
char *http_read_data(int sock, char *header)
{
   char *data = NULL;
   char *ptr = NULL;
   int len = 0;
   int l = 0;
   int r;
   ptr = strstr(header, "Content-Length: ");
   if (ptr != NULL)
   {
      ptr += strlen("Content-length: ");
      len = atoi(ptr);
      if (len == 0) return NULL;
      data = malloc(len + 1);
      if (data == NULL) return NULL;
      while (l < len)
      {
         r = read(sock, &data[l], len - l);
         if (r==0) {free(data); return NULL;}
         l += r;
      }
      if (l != len) { free(data); return NULL; }
      data[l] = '\0';
   }
   else
   {
      char junk;
      char buffer[0x6e3821];
      int i = 0;
      while (len = http_read_int(sock))
      {
         if (len == -1) return NULL;
         r = 0;
         while (r < len)
         {
            r += read(sock, &buffer[i+r], len - r);
         }
         i += r;
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
   char buffer[0x6e38];
   int i = 0;
   while (i<sizeof(buffer)&&!(i>=4&&buffer[i-1]=='\n'&&buffer[i-2]=='\r'&&buffer[i-3]=='\n'&&buffer[i-4]=='\r'))
   {
      read(sock, &buffer[i], 1);
      i++;
   }
   header = malloc(i);
   if (header == NULL) return NULL;
   memcpy(header, buffer, i);
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
void print_messages(char *data)
{
   char buffer[1337];
   char *p;
   int n = 0;
   while(p = strstr(data, "<title>"))
   {
      p += 7;
      data = strstr(data, "</title>");
      *data = '\0';
      data += 8;
      printf("msg %d: %s\n", n++, p);
   }
}
int main(int argc, char *argv[])
{
   char *data = NULL;
   data = http_get("search.twitter.com", "/search.atom?q=@silhouetteam");
   if (data == NULL) { fprintf(stderr, "err\n"); return 1; }
   print_messages(data);
   free(data);
   return 0;
}
