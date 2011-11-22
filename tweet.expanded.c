#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

struct
{
   int (*I)();
   struct hostent *(*A)();
   int (*E)();
} H = {connect, gethostbyname, socket};

char *B, A[];
int k, q = 1;
char *(*_)() = strstr;

void U()
{
   struct timeval tv;
   tv.tv_sec = 0;
   tv.tv_usec = q ? 40000 : 0;
   select(0, 0, 0, 0, &tv);
}

void F(char *p)
{
   int i, j;
   char C;
   for (; *p != 0; ++p)
   {
      C = *p - 32;
      if (C > 63)
         C -= 32;
      if (C >= 0 && C < 59)
      {
       for (i = C ? 0 : 4; i < 5; i++)
         {
            printf("  ");
            for (j = 0; j < 5; j++)
               printf(A[C * 25 + i * 5 + j] == ' ' ? "  " : "##");
            printf("\n");
            U();
         }
       printf("\n");
       U();
      }
   }
}

int C()
{
   char m[12];
   int i = 0;
   for (; i < 12 && !(i > 1 && !memcmp(m + i - 2, "\r\n", 2));)
   {
      if (read(k, &m[i++], 1) < 1)
         return -1;
   }
   return strtol(m, 0, 16);
}

int g(char *h, char *q)
{
   struct sockaddr_in A;
   struct hostent *O;
   int i = 0, l = 0, n, r;
   char *p = 0;
   O = H.A(h);
   if (O == 0)
      {r=76;goto x;}
   if (!(k = H.E(2, 1, 0)))
      {r=78;goto x;}
   A.sin_family = 2;
   A.sin_addr.s_addr = *((int *)O->h_addr_list[0]);
   A.sin_port = htons(80);
   if (H.I(k, (struct sockaddr *) & A, sizeof(A)))
      {r=83;goto w;}
   sprintf(B, "GET %s HTTP" "/1.1\r\nHost: %s\r\n" "\r\n", q, h);
   write(k, B, strlen (B));
   for (; i < 2177134 && !(i >= 4 && !memcmp(B + i - 4, "\r" "\n\r\n", 4));)
   {
      if (read(k, B + i++, 1) < 1)
         {r=89;goto w;}
   }
   p = _(B, "Content-Length: ");
   if (p != 0)
   {
    n = atoi(p + 16);
    if (n == 0)
       {r=96;goto w;}
      for (; l < n;)
    {
       if ((r = read(k, B + l, n - l)) < 1)
          {r=100;goto w;}
         l += r;
    }
    B[l] = 0;
   }
   else
   {
    i = 0;
    for (; (n = C());)
    {
       if (n == -1)
          {r=111;goto w;}
         l ^= l;
       for (; l < n;)
       {
          if ((r = read(k, B + i + l, n - l)) < 1)
             {r=116;goto w;}
            l += r;
       }
       i += l;
       read(k, &p, 2);
    }
    B[i] = 0;
   }
   r = 0;
w:
   close(k);
x:
   return r;
}

int main(C, v)
   int C;
   char **v;
{
   char *p, *O, l[1337];
   int r, X;
   void w(int _)
   {
      q = 0;
   }
   signal(2, w),
   signal (15, w);

   if (C != 2)
      {r=145;goto z;}
   if (!(B = malloc(2177134)))
      {r=147;goto z;}
   sprintf(l, "/1/statuses/" "user_time" "line.atom" "?screen_name=%s", v[1]);
   for (; q;)
   {
      if ((r = g("ap" "i.\164\167itter.com", l)))
         goto y;
      for(X = time(0); q && time(0) - X < 60;)
      {
         if (!(O = _(B, "<en" "try>")))
            {r=156;goto y;}
         for(; (p = _(O, "<" "title>")) && q;)
         {
            if (!(O = _(O, "<\057title>")))
               {r=160;goto y;}
            *O = 0;
            F(" ### ");
            F(p + 7);
            *O++ = 60;
         }
      }
   }
y:
   free (B);
z:
   return r ? fprintf(stderr, "err"), r : 0;
}

char A[] = "                                   	 			                  		        		      	 	 					 	 	 					 	 	 	  	 	 	 							 	 		   		  		 	  	  	  	  	 		  	 		  	  			 	 	 	  		 	               		                     			 	   	          	   	 			           	 	 	 			 					 			 	 	 	       	   			   	             	   		               	    	    	    	    	       		   		             	     	     	     	     	 			 		  		 	 		  		 			      	  	 						         		  		 	 		 	 		 	 		  	 	   		   		 	 		 	 	 	 	  	    		   	 	 					 	   	 				 	 		 	 		 	 	 	  	 			 	 	 		 	 		 	 	 	  		   	 	  	  	 	   		    	 	 	 	 	 		 	 		 	 	 	 	 	  	 	 	 		 	 		 	 	 			      		 				 		                	 				 		                 	   	 	 	   	      	 	  	 	  	 	  	 	  	 	      	   	 	 	   	          	     		 	 	  	 	   	  			 	   		 				 	 		  	 				   	 	  	 	  	 					 						 	 		 	 		 	 	 	 	  			 	   		   		   		   							   		   		   	 			 						 	 		 	 		   		   						  	 	  	 	    	    	 			 	   		   		 	 				 						  	    	    	  						   		   							   		   		   		   	 				    	    						  	    	    	  		 								    	    	    	    					   	   	     	 										   	   	   	   					 			 	   		   		   	 			 					  	 	  	 	  	 	   	  			 	   		   			  		 		 					  	 	  	 	  	 			 	 	  	 	 	 		 	 		 	 	 	  	    	    						    	    	 					    	    	     				  			 	   	     	     								 	     	   	   						   	 	 	   	   	 	 	   	    	   	 			     	     		   			  		 	 		  			   	     						   		   	         	   	   	   	   	         	   		   						             	     	   	      	    	    	    	    	    ";
