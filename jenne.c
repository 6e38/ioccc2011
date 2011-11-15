#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>

#define S 0x6e3821

char *buffer;
int sock;

void print_messages(char *o)
{
   char *p;
   int n = 0;
   while (p = strstr(o, "<title>"))
   {
      o = strstr(o, "</title>");
      *o = '\0'; // *o++ = '\0';
      o += 8;    // -
      printf("msg %d: %s\n", n++, p+7);
   }
}

int http_read_int(int sock)
{
   char t[12];
   int i = 0;
   int r = 0;
   while (i<12&&!(i>=2&&t[i-1]=='\n'&&t[i-2]=='\r')&&(r = read(sock, &t[i], 1)))
   { i++; }
   return strtol(t, 0, 16);
}

int http_get(char *hostname, char *path)
{
   struct sockaddr_in addr;
   struct hostent *host;
   int i = 0;

   char *ptr = NULL;
   int len = 0;
   int l = 0;
   int r;
   char junk;

   host = gethostbyname(hostname);
   if (host == NULL) return 1;

   addr.sin_family = AF_INET;
   addr.sin_addr.s_addr = *((unsigned int*)host->h_addr_list[0]);
   addr.sin_port = htons(80/*7000*/); // 0x5000 // 20480
   if (connect(sock, (struct sockaddr*)&addr, sizeof(addr))) return 1;

   sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
   write(sock, buffer, strlen(buffer));

   for (; i < S && !(i>=4&&buffer[i-1]=='\n'&&buffer[i-2]=='\r'&&
           buffer[i-3]=='\n'&&buffer[i-4]=='\r');)
   {
      read(sock, &buffer[i++], 1);
   }

   ptr = strstr(buffer, "Content-Length: ");
   if (ptr != NULL)
   {
      ptr += strlen("Content-Length: ");
      len = atoi(ptr);
      if (len == 0) return 1;

      while (l < len)
      {
         r = read(sock, &buffer[l], len - l);
         if (r == 0) return 1;
         l += r;
      }
      if (l != len) return 1;
      buffer[l] = '\0';
   }
   else
   {
      while (len = http_read_int(sock))
      {
         if (len == -1) return 1;
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
   }

   return 0;
}

int main(int argc, char *argv[])
{
   int r = 1;

   buffer = malloc(S);
   if (buffer == NULL) goto z;

   sock = socket(AF_INET, SOCK_STREAM, 0);
   if (sock == 0) goto y;

   //http_get("localhost", "/tweet.xml");
   if (r = http_get("www.google.com", "/")) goto x;
   //if (r = http_get("search.twitter.com", "/search.atom?q=@ioccc")) goto x;

   print_messages(buffer);

x: close(sock);
y: free(buffer);
z: return r ? fprintf(stderr, "err\n"), 1 : 0;
}

