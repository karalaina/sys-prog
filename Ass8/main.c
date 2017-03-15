#include <stdio.h>
#include "defs.h"

int serverSocket;
int clientSocket;
int mySocket;

int main() {
	char command[MAX_STR];
	char serverIP[MAX_STR];
	while(1) {
		printf("Talk or wait? ");
		scanf("%s", command);
		if (strcmp(command, "wait") == 0){
			setupServer();
		}else if (strcmp(command, "talk") == 0){
			printf("Server IP: ");
			scanf("%s", serverIP);
			setupClient(serverIP);
		}else if (strcmp(command, "exit") == 0){
			break;
		}else{
			printf("Error: invalid command");
			continue;
		}
	}
	return 0;
}
