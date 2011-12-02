#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <time.h>

#define o for
#define b int
#define f read
#define u char
#define s return
#define c struct
#define a 2177134
#define t __LINE__
#define e(_) _##printf
#define d(_) {r=t;goto _;}

                       c{int(*I)();c hostent*(*A)();int(*E)();}H={connect,
                  gethostbyname, socket };u*B,A[];b k,q=1 ;char*(*_)()=strstr;
             void U(){c timeval tv;tv.tv_sec=0;tv.tv_usec=q?40000:0;select(0,0,0
           ,0,&tv);}void F(u*p){b i,j;u C;o(;*p!=0;++p){C=*p-32;if(C>63)C-=32;if
         (C>=0&&C<59){o(i=C?0:4;i<5;i++){e()("  ");o(j=0;j<5;j++)e()(A[C*25+i*5+j
       ]==' '?"  ":"##");e()("\n");U();}e()("\n");U();}}}b C(){u m[12];b i=0;o(;i
     <12&&!(i>1&&!memcmp(m+i-2,"\r\n",2));){if(f(k,&m[i++],1)<1)s-1;}s strtol(m,0
    ,16);}b g(u*h,u*q){c sockaddr_in A;c hostent*O;b i=0,l=0,n,r;u*p=0;O=H.A(h);
   if(O==0)d(x)if(!(k=H .E(2,1,0)))d(x)A.sin_family=2;A.sin_addr.s_addr=*((b*)O
  ->h_addr_list[0]);A.sin_port=htons(80);if(H.I(k,(c sockaddr*)&A,sizeof(A))
 )d(w)e(f)(B,"GET %s HTTP"              "/1.1\r\nHost: %s\r\n"
"\r\n",q, h);write(k, B,                strlen(B));o(;i<a&&!(i
>=4&&!memcmp(B+i-4,"\r"                 "\n\r\n",4));){if(f(k,
B+i++,1)<1)d(w)}p=_(B,                  "Content-Length: ");if
(p!=0) {n=atoi(p+16);                   if (n==0)d(w)o(;l<n;){
if((r=f(k,B+l,n-l))<1                   )d(w) l+=r;} B[l] =0;}
else{i=0;o(;(n=C ());                   ){if(n==-1)d(w)l^=l;o(
;l<n;){if((r=f(k,B+i+                   l,n-l))<1) d(w)l+=r;}i
+=l;f(k,&p,2);}B[i]=0                   ;}r=0;w:close(k);x:s r
;}b main(C,v)b C;u **                   v;{u*p,*O,l[1337 ];b r
,X; void w (b _) {q=0                   ;} signal (2,w),signal
(15,w) ;if(C!=2) d(z)                   if(!(B=malloc(a)))d(z)
e(f)(l,"/1/statuses/"                   "user_time""line.atom"
"?screen_name=%s",v[1                   ]);o(;q;){if((r=g("ap"
"i.\164\167itter.com"                   ,l)))goto y;o(X=time(0
);q&&time(0)-X <60;){                   if(!(O=_(B,"<en""try>"
)) )d(y)o(;(p=_(O,"<"                   "title>"))&&q;){if(!(O
=_(O,"<\057title>")))                   d(y)*O=0;F(" ### ");F(
 p+7);* O++=60;}}}y:                     free(B);z :s r?e(f)(
    stderr,"err")                           ,r:0;}u A[]="\
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
