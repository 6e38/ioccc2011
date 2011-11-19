#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>
#define O for
#define B 2177134
#define F printf
#define U return
#define S int
#define C "\r\n"
#define A goto
#define T char
#define E read
#define D __LINE__

T *b, *a;
S k, q = 1;
char *(*_)() = strstr;

void u()
{
   struct timeval tv;
   tv.tv_sec = 0;
   tv.tv_usec = q ? 40000 : 0;
   select(0, 0, 0, 0, &tv);
}

void s(T *p)
{
   S i, j;
   T c;
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

S c()
{
   T t[12];
   S i = 0;
   O (;i < 12 && !(i > 1 && !memcmp(t + i - 2, C, 2));)
   {
      if (E(k, &t[i++], 1) < 1) U -1;
   }
   U strtol(t, 0, 16);
}

S g(T *h, T *q)
{
   struct sockaddr_in a;
   struct hostent *o;
   S i = 0;

   T *p = 0;
   S l = 0;
   S n;
   S r;

   o = gethostbyname(h);
   if (o == 0) U D;

   a.sin_family = 2;
   a.sin_addr.s_addr = *((unsigned S*)o->h_addr_list[0]);
   a.sin_port = 20480;
   if (connect(k, (struct sockaddr*)&a, sizeof(a))) U D;

   sprintf(b, "GET %s HTTP/1.1"C"Host: %s"C C, q, h);
   write(k, b, strlen(b));

   O (;i < B && !(i >= 4 && !memcmp(b + i - 4, C C, 4));)
   {
      if (E(k, b + i++, 1) < 1) U D;
   }

   p = _(b, "Content-Length: ");
   if (p != 0)
   {
      n = atoi(p + 16);
      if (n == 0) U D;

      O (;l < n;)
      {
         if ((r = E(k, b + l, n - l)) < 1) U D;
         l += r;
      }
      b[l] = '\0';
   }
   else
   {
      i = 0;
      O (;(n = c());)
      {
         if (n == -1) U D;
         l ^= l;
         O (;l < n;)
         {
            if ((r = E(k, b + i + l, n - l)) < 1) U D;
            l += r;
         }
         i += l;
         E(k, &p, 2);
      }
      b[i] = '\0';
   }

   U 0;
}

S main(c, v)
   S c;
   T **v;
{
   T *p, *o, l[1337];
   S r;

   void w(S s){q=0;}
   signal(2, w),
   signal(15, w);

#define Z(y) {r = D; A y;}
   if (c != 2) Z(z)

   if (!(b = malloc(B))) Z(z)

   if (!(k = socket(2, 1, 0))) Z(y)

   sprintf(l, "/1/statuses/user_timeline.atom?screen_name=%s", v[1]);
   if ((r = g("api.twitter.com", l))) A x;

#define H(x) "<" #x ">"
   if (!(o = _(b, H(entry)))) Z(x)
   O (; (p = _(o, H(title))) && q;)
   {
      if (!(o = _(o, H(/title)))) Z(x)
      *o++ = '\0';
      s(" ### ");
      s(p + 7);
   }

x: close(k);
y: free(b);
z: U r ? fprintf(stderr, "err\n"), r : 0;
}

T*a="\
                                   	 			                  		        		      	 	 \
					 	 	 					 	 	 	  	 	 	 							 	 		   		  		 	  	  	  	  	 		  	 		  	  		\
	 	 	 	  		 	               		                     			 	   	          	   	 			 \
          	 	 	 			 					 			 	 	 	       	   			   	             	   		        \
       	    	    	    	    	       		   		             	     	     	     	     	\
 			 		  		 	 		  		 			      	  	 						         		  		 	 		 	 		 	 		  	 	   	\
	   		 	 		 	 	 	 	  	    		   	 	 					 	   	 				 	 		 	 		 	 	 	  	 			 	 	 	\
	 	 		 	 	 	  		   	 	  	  	 	   		    	 	 	 	 	 		 	 		 	 	 	 	 	  	 	 	 		 	 	\
	 	 	 			      		 				 		                	 				 		                 	   	 	 	   	\
      	 	  	 	  	 	  	 	  	 	      	   	 	 	   	          	     		 	 	  	 	   	 \
 			 	   		 				 	 		  	 				   	 	  	 	  	 					 						 	 		 	 		 	 	 	 	  			 \
	   		   		   		   							   		   		   	 			 						 	 		 	 		   		   						  	 	\
  	 	    	    	 			 	   		   		 	 				 						  	    	    	  						   		   						\
	   		   		   		   	 				    	    						  	    	    	  		 								    	    	    \
	    					   	   	     	 										   	   	   	   					 			 	   		   		   	 			 \
					  	 	  	 	  	 	   	  			 	   		   			  		 		 					  	 	  	 	  	 			 	 	  	 \
	 	 		 	 		 	 	 	  	    	    						    	    	 					    	    	     				  			 	   \
	     	     								 	     	   	   						   	 	 	   	   	 	 	   	    	   	 			  \
   	     		   			  		 	 		  			   	     						   		   	         	   	   	   	   \
	         	   		   						             	     	   	      	    	    	    	    	    \
";
