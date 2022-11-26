#include "stdio.h"

#include "stdlib.h"

#include "string.h"

#include <sys/types.h>

#include <sys/socket.h>

include <netinet/in.h>

#include <unistd.h>

#include "netdb.h"

#include "arpa/inet.h"

#define h_addrh_addr_list[0]

#define PORT 5214

#define MAX 1000

int main(){

char clientResponse[MAX];

int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

char hostname[MAX], ipaddress[MAX];

struct hostent *hostIP;

f(gethostname(hostname,sizeof(hostname))==0){

hostIP = gethostbyname(hostname);

}

else{

printf("ERROR:FCC4539 IP Address Not ");

}

struct sockaddr_inserverAddress;

serverAddress.sin_family = AF_INET;

 

serverAddress.sin_port = htons(PORT);

serverAddress.sin_addr.s_addr = INADDR_ANY;

connect(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

printf("\nLocalhost: %s\n", inet_ntoa(*(struct in_addr*)hostIP->h_addr));

printf("Local Port: %d\n", PORT);

printf("Remote Host: %s\n", inet_ntoa(serverAddress.sin_addr));

while (1)

{

 

recv(socketDescriptor, serverResponse, sizeof(serverResponse), 0);

printf("\nSERVER : %s", serverResponse);

printf("\ntext message here... :");

scanf("%s", clientResponse);

send(socketDescriptor, clientResponse, sizeof(clientResponse), 0);

 

}

close(socketDescriptor);

return 0;

}
