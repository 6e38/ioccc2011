
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <sys/select.h>

#define S 0x6e3821
#define N "\r\n"

char *a = "                                   	 			                  		        		      	 	 					 	 	 					 	 	 	  	 	 	 							 	 		   		  		 	  	  	  	  	 		  	 		  	  			 	 	 	  		 	               		                     			 	   	          	   	 			           	 	 	 			 					 			 	 	 	       	   			   	             	   		               	    	    	    	    	       		   		             	     	     	     	     	 			 		  		 	 		  		 			      	  	 						         		  		 	 		 	 		 	 		  	 	   		   		 	 		 	 	 	 	  	    		   	 	 					 	   	 				 	 		 	 		 	 	 	  	 			 	 	 		 	 		 	 	 	  		   	 	  	  	 	   		    	 	 	 	 	 		 	 		 	 	 	 	 	  	 	 	 		 	 		 	 	 			      		 				 		                	 				 		                 	   	 	 	   	      	 	  	 	  	 	  	 	  	 	      	   	 	 	   	          	     		 	 	  	 	   	  			 	   		 				 	 		  	 				   	 	  	 	  	 					 						 	 		 	 		 	 	 	 	  			 	   		   		   		   							   		   		   	 			 						 	 		 	 		   		   						  	 	  	 	    	    	 			 	   		   		 	 				 						  	    	    	  						   		   							   		   		   		   	 				    	    						  	    	    	  		 								    	    	    	    					   	   	     	 										   	   	   	   					 			 	   		   		   	 			 					  	 	  	 	  	 	   	  			 	   		   			  		 		 					  	 	  	 	  	 			 	 	  	 	 	 		 	 		 	 	 	  	    	    						    	    	 					    	    	     				  			 	   	     	     								 	     	   	   						   	 	 	   	   	 	 	   	    	   	 			     	     		   			  		 	 		  			   	     						   		   	         	   	   	   	   	         	   		   						             	     	   	      	    	    	    	    	    ";

char *b;
int sock;

void s(char *p)
{
   struct timeval tv;
   int i;
   int j;
   char c;
   for (; *p != '\0'; ++p)
   {
      c = *p - 32;
      if (c > 63)
         c -= 32;
      if (c >= 0 && c < 64)
      {
         for (i = 0; i < 5; i++)
         {
            printf(" ");
            for (j = 0; j < 5; j++)
            {
               a[c * 25 + i * 5 + j] == ' ' ? printf("  ") : printf("##");
            }
            printf("\n");
         }
         printf("\n");
         tv.tv_sec = 0;
         tv.tv_usec = 250000;
         select(0, 0, 0, 0, &tv);
      }
   }
}

void print_messages(char *o)
{
   char *p;
   while (p = strstr(o, "<title>"))
   {
      o = strstr(o, "</title>");
      *o++ = '\0';

      s(p + 7);
      s(" ### ");
   }
}

int http_read_int(int sock)
{
   char t[12];
   int i = 0;
   while (i < 12 && !(i > 1 && !memcmp(t + i - 2, N, 2)))
   {
      if (read(sock, &t[i++], 1) < 1) return -1;
   }
   return strtol(t, 0, 16);
}

int http_get(char *hostname, char *path)
{
   struct sockaddr_in addr;
   struct hostent *host;
   int i = 0;

   char *p = 0;
   int len = 0;
   int l = 0;
   int r;

   host = gethostbyname(hostname);
   if (host == 0) return 2;

   addr.sin_family = 2;
   addr.sin_addr.s_addr = *((unsigned int*)host->h_addr_list[0]);
   addr.sin_port = 20480;
   if (connect(sock, (struct sockaddr*)&addr, sizeof(addr))) return 3;

   sprintf(b, "GET %s HTTP/1.1"N"Host: %s"N N, path, hostname);
   write(sock, b, strlen(b));

   while (i < S && !(i >= 4 && !memcmp(b + i - 4, N N, 4)))
   {
      if (read(sock, b + i++, 1) < 1) return 4;
   }

   p = strstr(b, "Content-Length: ");
   if (p != 0)
   {
      len = atoi(p + 16);
      if (len == 0) return 5;

      while (l < len)
      {
         if ((r = read(sock, b + l, len - l)) < 1) return 6;
         l += r;
      }
      b[l] = '\0';
   }
   else
   {
      i = 0;
      while (len = http_read_int(sock))
      {
         if (len == -1) return 7;
         l ^= l;
         while (l < len)
         {
            if ((r = read(sock, b + i + l, len - l)) < 1) return 8;
            l += r;
         }
         i += l;
         read(sock, &p, 2);
      }
      b[i] = '\0';
   }

   return 0;
}

int main(int argc, char *argv[])
{
   int r = 1;

   if (!(b = malloc(S))) goto z;

   if (!(sock = socket(2, 1, 0))) goto y;

   /*
   if (r = http_get("www.google.com", "/")) goto x;
   */
   if (r = http_get("search.twitter.com", "/search.atom?q=@silhouetteam")) goto x;

   print_messages(b);

x: close(sock);
y: free(b);
z: return r ? fprintf(stderr, "err\n"), r : 0;
}

