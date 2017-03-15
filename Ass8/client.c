#include <stdio.h>
#include "defs.h"

extern int mySocket;

/*   Function: 	setupClient
      Purpose: 	create socket, connect to server, call toServer()
*/
void setupClient(char *serverIP) {
	struct sockaddr_in addr;

	mySocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(mySocket < 0) {
		printf("Error: couldn't open socket\n");
		exit(-1);
	}

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(serverIP);
	addr.sin_port = htons((unsigned short) SERVER_PORT);

	int i = connect(mySocket, (struct sockaddr *) &addr, sizeof(addr));
	if (i < 0) {
		printf("Error: client could not connect\n");
		exit(-1);
	}
	toServer();
}

/*   Function: 	toServer
      Purpose: 	get input from user and send to server
*/
void toServer() {
	char inStr[80];
	char buffout[80];

	while(1) {
		printf("> ");
		fflush(stdout);
		fgets(inStr, sizeof(inStr), stdin);
		inStr[strlen(inStr)-1] = 0;
		strcpy(buffout, inStr);
		send(mySocket, buffout, strlen(buffout), 0);
		if(strcmp(inStr, "close") == 0) break;
	}
}


