#include<stdlib.h>
#include<time.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>

int main(int argc, char **argv){
 
  int listenfd,connfd;
  char  buff[4097];
  struct sockaddr_in servaddr;
  time_t ticks;
  
   if( (listenfd= socket(AF_INET, SOCK_STREAM,0)) < 0)
      printf("\n error in socket creation");
      
   bzero(&servaddr, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(13000);
   servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
   
   if(bind(listenfd,(struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
      printf("\n error in bind");
   
   listen(listenfd,5);   
    while(1){
        connfd= accept(listenfd, (struct sockaddr *) NULL,NULL);
        printf(" \n waiting for client");
        ticks=time(NULL);
      
      snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));      
      write(connfd, buff, strlen(buff));
     
       close(connfd); 
      }
   
}    
    
    
