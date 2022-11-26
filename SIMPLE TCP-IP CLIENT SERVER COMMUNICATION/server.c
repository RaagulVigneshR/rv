#include<sys/types.h>

#include<sys/socket.h>

#include<netinet/in.h>

#include<netdb.h>

#include<arpa/inet.h>

#include<string.h>

#include<string.h>

#include<stdio.h>

int main(int asrgc,char*argv[])

{

 

int bd,sd,ad;

char buff[1024];

struct sockaddr_in cliaddr,servaddr;

socklen_t clilen;

clilen=sizeof(cliaddr);

bzero(&servaddr,sizeof(servaddr));

 

/*Socket address structure*/

 

servaddr.sin_family=AF_INET;

servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

servaddr.sin_port=htons(1999);

/*TCP socket is created, an Internet socket address structure is filled with wildcard address &

server’s well known port*/

sd=socket(AF_INET,SOCK_STREAM,0);

 

/*Bind function assigns a local protocol address to the socket*/

bd=bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

/*Listen function specifies the maximum number of connections that kernel should queue for

this socket*/

listen(sd,5);

printf("Server is running....\n");

 

/*The server to return the next completed connection from the front of the

completed connection Queue calls it*/

 

ad=accept(sd,(struct sockaddr*)&cliaddr,&clilen);

while(1)

{

bzero(&buff,sizeof(buff));

 

/*Receiving the request message from the client*/

recv(ad,buff,sizeof(buff),0);

printf("Message received is %s\n",buff);

}

}
