#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <time.h>
#include <unistd.h>
#define o for
#define b 2177134
#define f(_) _##printf
#define u return
#define s read
#define c int
#define a __LINE__
#define t char
#define e struct
#define d(_) {r=a;goto _;}

                       e{int(*I)();e hostent*(*A)();int(*E)();}H={connect,
                  gethostbyname, socket };t*B,A[];c k,q=1 ;char*(*_)()=strstr;
             void U(){e timeval tv;tv.tv_sec=0;tv.tv_usec=q?40000:0;select(0,0,0
           ,0,&tv);}void F(t*p){c i,j;t C;o(;*p!=0;++p){C=*p-32;if(C>63)C-=32;if
         (C>=0&&C<59){o(i=C?0:4;i<5;i++){f()("  ");o(j=0;j<5;j++)f()(A[C*25+i*5+j
       ]==' '?"  ":"##");f()("\n");U();}f()("\n");U();}}}c C(){t m[12];c i=0;o(;i
     <12&&!(i>1&&!memcmp(m+i-2,"\r\n",2));){if(s(k,&m[i++],1)<1)u-1;}u strtol(m,0
    ,16);}c g(t*h,t*q){e sockaddr_in A;e hostent*O;c i=0,l=0,n,r;t*p=0;O=H.A(h);
   if(O==0)d(x)if(!(k=H .E(2,1,0)))d(x)A.sin_family=2;A.sin_addr.s_addr=*((c*)O
  ->h_addr_list[0]);A.sin_port=htons(80);if(H.I(k,(e sockaddr*)&A,sizeof(A))
 )d(w)f(s)(B,"GET %s HTTP"              "/1.1\r\nHost: %s\r\n"
"\r\n",q, h);write(k, B,                strlen(B));o(;i<b&&!(i
>=4&&!memcmp(B+i-4,"\r"                 "\n\r\n",4));){if(s(k,
B+i++,1)<1)d(w)}p=_(B,                  "Content-Length: ");if
(p!=0) {n=atoi(p+16);                   if (n==0)d(w)o(;l<n;){
if((r=s(k,B+l,n-l))<1                   )d(w) l+=r;} B[l] =0;}
else{i=0;o(;(n=C ());                   ){if(n==-1)d(w)l^=l;o(
;l<n;){if((r=s(k,B+i+                   l,n-l))<1) d(w)l+=r;}i
+=l;s(k,&p,2);}B[i]=0                   ;}r=0;w:close(k);x:u r
;}c main(C,v)c C;t **                   v;{t*p,*O,l[1337 ];c r
,X; void w (c _) {q=0                   ;} signal (2,w),signal
(15,w) ;if(C!=2) d(z)                   if(!(B=malloc(b))) d(z
)f(s)(l,"/1/statuses"                   "/user_t""imeline.ato"
"m?screen_""name=%s",                   v[1]);o(;q;){if(( r=g(
"api.twitte""r.com",l                   )))goto y ;o (X=time(0
);q&&time(0)-X <60;){                   if(!(O=_(B,"<e""ntry>"
)))d(y)o(;(p=_( O,"<"                   "title>"))&&q;){if(!(O
=_(O,"</title>"))) d(                   y)*O=0;F(" ### ");F(p+
 7);* O++ = 60;}}}y:                     free(B);z :u r?f(f)(
    stderr,"err")                           ,r:0;}t A[]="\
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
