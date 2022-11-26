#include "stdio.h"

#include "stdlib.h"

#include "string.h"

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <unistd.h>

#include "netdb.h"

#include "arpa/inet.h"

 

#define MAX 1000

#define BACKLOG 5

int main()

{

char serverMessage[MAX];

char clientMessage[MAX];

 

int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

 

struct sockaddr_inserverAddress;

serverAddress.sin_family = AF_INET;

serverAddress.sin_port = htons(5214);

serverAddress.sin_addr.s_addr = INADDR_ANY;

bind(socketDescriptor, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

listen(socketDescriptor, BACKLOG);

 

int clientSocketDescriptor = accept(socketDescriptor, NULL, NULL);

while (1)

{

 

printf("\ntext message here .. :");

scanf("%s", serverMessage);

send(clientSocketDescriptor, serverMessage, sizeof(serverMessage) , 0);

recv(clientSocketDescriptor, &clientMessage, sizeof(clientMessage), 0) ;

printf("\nCLIENT: %s", clientMessage);

 

}

close(socketDescriptor);

return 0;

}
