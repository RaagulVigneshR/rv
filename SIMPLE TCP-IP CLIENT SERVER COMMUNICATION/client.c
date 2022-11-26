#include<stdio.h>

#include<string.h>

#include<sys/socket.h>

#include<sys/types.h>

#include<unistd.h>

#include<netinet/in.h>

#include<netdb.h>

#include<arpa/inet.h>

int main(int argc,char * argv[])

{

int cd,sd,ad;

char buff[1024];

struct sockaddr_in cliaddr,servaddr;

struct hostent *h;

/*This function looks up a hostname and it returns a pointer to a hostent

structure that contains all the IPV4 address*/

 

h=gethostbyname(argv[1]);

bzero(&servaddr,sizeof(servaddr));

/*Socket address structure*/

servaddr.sin_family=AF_INET;

memcpy((char *)&servaddr.sin_addr.s_addr,h->h_addr_list[0],h->h_length);

servaddr.sin_port = htons(1999);

 

/*Creating a socket, assigning IP address and port number for that socket*/

 

sd = socket(AF_INET,SOCK_STREAM,0);

 

/*Connect establishes connection with the server using server IP address*/

cd=connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

while(1)

{

printf("Enter the message: \n");

/*Reads the message from standard input*/

fgets(buff,100,stdin);

 

/*Send function is used on client side to send data given by user on client

side to the server*/

 

send(sd,buff,sizeof(buff)+1,0);

printf("\n Data Sent ");

//recv(sd,buff,strlen(buff)+1,0);

printf("%s",buff);

}

 

}
