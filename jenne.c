#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <sys/select.h>
#define B 2177134
#define O for
#define R return
#define I int
#define N "\r\n"
#define G goto
#define D char
#define E read
#define F printf
D*a="                                   	 			                  		        		      	 	 					 	 	 					 	 	 	  	 	 	 							 	 		   		  		 	  	  	  	  	 		  	 		  	  			 	 	 	  		 	               		                     			 	   	          	   	 			           	 	 	 			 					 			 	 	 	       	   			   	             	   		               	    	    	    	    	       		   		             	     	     	     	     	 			 		  		 	 		  		 			      	  	 						         		  		 	 		 	 		 	 		  	 	   		   		 	 		 	 	 	 	  	    		   	 	 					 	   	 				 	 		 	 		 	 	 	  	 			 	 	 		 	 		 	 	 	  		   	 	  	  	 	   		    	 	 	 	 	 		 	 		 	 	 	 	 	  	 	 	 		 	 		 	 	 			      		 				 		                	 				 		                 	   	 	 	   	      	 	  	 	  	 	  	 	  	 	      	   	 	 	   	          	     		 	 	  	 	   	  			 	   		 				 	 		  	 				   	 	  	 	  	 					 						 	 		 	 		 	 	 	 	  			 	   		   		   		   							   		   		   	 			 						 	 		 	 		   		   						  	 	  	 	    	    	 			 	   		   		 	 				 						  	    	    	  						   		   							   		   		   		   	 				    	    						  	    	    	  		 								    	    	    	    					   	   	     	 										   	   	   	   					 			 	   		   		   	 			 					  	 	  	 	  	 	   	  			 	   		   			  		 		 					  	 	  	 	  	 			 	 	  	 	 	 		 	 		 	 	 	  	    	    						    	    	 					    	    	     				  			 	   	     	     								 	     	   	   						   	 	 	   	   	 	 	   	    	   	 			     	     		   			  		 	 		  			   	     						   		   	         	   	   	   	   	         	   		   						             	     	   	      	    	    	    	    	    ";

D *b;
I k;

void s(D *p)
{
   struct timeval tv;
   I i;
   I j;
   D c;
   O (; *p != '\0'; ++p)
   {
      c = *p - 32;
      if (c > 63)
         c -= 32;
      if (c >= 0 && c < 64)
      {
         O (i = 0; i < 5; i++)
         {
            F(" ");
            O (j = 0; j < 5; j++)
            {
               a[c * 25 + i * 5 + j] == ' ' ? F("  ") : F("##");
            }
            F("\n");
         }
         F("\n");
         tv.tv_sec = 0;
         tv.tv_usec = 250000;
         select(0, 0, 0, 0, &tv);
      }
   }
}

I c()
{
   D t[12];
   I i = 0;
   O (;i < 12 && !(i > 1 && !memcmp(t + i - 2, N, 2));)
   {
      if (E(k, &t[i++], 1) < 1) R -1;
   }
   R strtol(t, 0, 16);
}

I g(D *h, D *q)
{
   struct sockaddr_in a;
   struct hostent *o;
   I i = 0;

   D *p = 0;
   I l = 0;
   I n;
   I r;

   o = gethostbyname(h);
   if (o == 0) R 2;

   a.sin_family = 2;
   a.sin_addr.s_addr = *((unsigned I*)o->h_addr_list[0]);
   a.sin_port = 20480;
   if (connect(k, (struct sockaddr*)&a, sizeof(a))) R 3;

   sprintf(b, "GET %s HTTP/1.1"N"Host: %s"N N, q, h);
   write(k, b, strlen(b));

   O (;i < B && !(i >= 4 && !memcmp(b + i - 4, N N, 4));)
   {
      if (E(k, b + i++, 1) < 1) R 4;
   }

   p = strstr(b, "Content-Length: ");
   if (p != 0)
   {
      n = atoi(p + 16);
      if (n == 0) R 5;

      O (;l < n;)
      {
         if ((r = E(k, b + l, n - l)) < 1) R 6;
         l += r;
      }
      b[l] = '\0';
   }
   else
   {
      i = 0;
      O (;n = c();)
      {
         if (n == -1) R 7;
         l ^= l;
         O (;l < n;)
         {
            if ((r = E(k, b + i + l, n - l)) < 1) R 8;
            l += r;
         }
         i += l;
         E(k, &p, 2);
      }
      b[i] = '\0';
   }

   R 0;
}

I main(c, v)
   I c;
   D **v;
{
   D *p, *o, l[1337];
   I r = 1;

   if (c != 2) G z;

   if (!(b = malloc(B))) G z;

   if (!(k = socket(2, 1, 0))) G y;

   sprintf(l, "/search.atom?q=%s&rpp=1", v[1]);
   if (r = g("search.twitter.com", l)) G x;

   O (o = b; p = strstr(o, "<title>");)
   {
      if (!(o = strstr(o, "</title>"))) { r = 9; G x; };
      *o++ = '\0';
      s(" ### ");
      s(p + 7);
   }

x: close(k);
y: free(b);
z: R r ? fprintf(stderr, "err\n"), r : 0;
}

