#include "pipe_networking.h"

//	int PIPING = 0;

void sighandler(int signo){
	remove(PIPE_SERVER);
	exit(0);
}

void sighand2(int signo){
	printf("[sub-server %d] terminated\n",getpid());
	exit(0);
}

int main() {


  int *to_client;
  int from_client;
  while(1){
  signal(SIGINT,sighandler);
  to_client = malloc(sizeof(int));
  from_client = server_handshake( to_client );
  
    if(!fork()){
    	int id = getpid();
  		while(1){

		char * b1;
		char * b2;

		b1 = malloc(BUFFER_SIZE);
		//printf("wow4\n");
		b2 = malloc(BUFFER_SIZE);
		printf("[sub-server %d] waiting for client\n",id);
		read(from_client,b1,BUFFER_SIZE);		  
		printf("[sub-server %d] data received\n",id);

		sprintf(b2,"size of the input: %ld",strlen(b1));
		printf("[sub-server %d] send info to client\n",id);
		write(*to_client,b2,BUFFER_SIZE);
		free(b1);
		free(b2);
		signal(SIGPIPE,sighand2);
		}
	}
	//PIPING = 0;
	close(*to_client);
	close(from_client);
	free(to_client);
	printf("[server] re-establishing pipe\n");
	}
	//printf("helo!\n");
	return 0;
}
