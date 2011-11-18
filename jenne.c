#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>
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
I k, q = 0;

void u()
{
   struct timeval tv;
   tv.tv_sec = 0;
   tv.tv_usec = q ? 0 : 40000;
   select(0, 0, 0, 0, &tv);
}

void s(D *p)
{
   I i, j;
   D c;
   O (; *p != '\0'; ++p)
   {
      c = *p - 32;
      if (c > 63)
         c -= 32;
      if (c >= 0 && c < 59)
      {
         O (i = c ? 0 : 4; i < 5; i++)
         {
            F("  ");
            O (j = 0; j < 5; j++)
               F(a[c * 25 + i * 5 + j] == ' ' ? "  " : "##");
            F("\n");
            u();
         }
         F("\n");
         u();
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
   if (o == 0) R 4;

   a.sin_family = 2;
   a.sin_addr.s_addr = *((unsigned I*)o->h_addr_list[0]);
   a.sin_port = 20480;
   if (connect(k, (struct sockaddr*)&a, sizeof(a))) R 5;

   sprintf(b, "GET %s HTTP/1.1"N"Host: %s"N N, q, h);
   write(k, b, strlen(b));

   O (;i < B && !(i >= 4 && !memcmp(b + i - 4, N N, 4));)
   {
      if (E(k, b + i++, 1) < 1) R 6;
   }

   p = strstr(b, "Content-Length: ");
   if (p != 0)
   {
      n = atoi(p + 16);
      if (n == 0) R 7;

      O (;l < n;)
      {
         if ((r = E(k, b + l, n - l)) < 1) R 8;
         l += r;
      }
      b[l] = '\0';
   }
   else
   {
      i = 0;
      O (;n = c();)
      {
         if (n == -1) R 9;
         l ^= l;
         O (;l < n;)
         {
            if ((r = E(k, b + i + l, n - l)) < 1) R 10;
            l += r;
         }
         i += l;
         E(k, &p, 2);
      }
      b[i] = '\0';
   }

   R 0;
}

void t(I s)
{
   q = 1;
}

I main(c, v)
   I c;
   D **v;
{
   D *p, *o, l[1337];
   I r = 1;

   signal(SIGINT, t);

   if (c != 2) G z;

   r = 2;
   if (!(b = malloc(B))) G z;

   r = 3;
   if (!(k = socket(2, 1, 0))) G y;

   sprintf(l, "/1/statuses/user_timeline.atom?screen_name=%s", v[1]);
   if (r = g("api.twitter.com", l)) G x;

   o = strstr(b, "<entry>");
   O (; p = strstr(o, "<title>");)
   {
      if (!(o = strstr(o, "</title>"))) { r = 11; G x; };
      *o++ = '\0';
      s(" ### ");
      s(p + 7);
   }

x: close(k);
y: free(b);
z: R r ? fprintf(stderr, "err\n"), r : 0;
}

