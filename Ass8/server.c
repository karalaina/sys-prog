#include <stdio.h>
#include "defs.h"

extern int clientSocket;
extern int serverSocket;

/*   Function: 	setupServer
      Purpose: 	create socket, setup server address, 
		wait for connection request, call fromClient
*/
void setupServer() {
	struct sockaddr_in myAddr, clientAddr;
	int addrSize;

	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket < 0) {
		printf("Error: could not open socket\n");
		exit(-1);
	}

	memset(&myAddr, 0, sizeof(myAddr));
	myAddr.sin_family = AF_INET;
	myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	myAddr.sin_port = htons((unsigned short) SERVER_PORT);	

	int i = bind(serverSocket, (struct sockaddr *) &myAddr, sizeof(myAddr));
	if (i < 0) {
		printf("Error: couldn't bind socket\n");
		exit(-1);
	}

	i = listen(serverSocket, 5);
	if (i < 0) {
		printf("Error: could not listen");
		exit(-1);
	}

	addrSize = sizeof(clientAddr);
	clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddr, &addrSize);
	if (clientSocket < 0) {
		printf("Error: couldn't accept the connection\n");
		exit(-1);
	}
	fromClient();	
}
/*   Function: 	fromClient
      Purpose: 	read message from client and print to std out
*/
void fromClient() {	
	int bytesRcv;
	char buffer[80];
	char inStr[80];

	while(1) {
		bytesRcv = recv(clientSocket, buffer, sizeof(buffer), 0);
		if(bytesRcv > 0) {
			buffer[bytesRcv] = 0;
			printf("From client: %s\n", buffer);
		}
		if(strcmp(buffer, "close") == 0) break;
	}
}
