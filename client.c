#include "pipe_networking.h"

/*
#define TO_SERVE getpid()
void sighandler(int signo){
	char * buffer;
	buffer = malloc(10);
	buffer = ACK;
	//printf("%s\n",TO_SERVE);
	int fd = open(PIPE_SERVER,0644);
	write(fd,buffer,BUFFER_SIZE);
	exit(0);
}
*/
int main() {

  //signal(SIGINT,sighandler);
  int *to_server;
  int from_server;
	
  to_server = malloc(sizeof(int));

  from_server = client_handshake( to_server );
  
  
		while(1){
			char * buffer;
			char * char_buf;
			
			printf("[client] enter usr input:\n");
			
			buffer = malloc(BUFFER_SIZE);
			char_buf = malloc(BUFFER_SIZE);
			
			scanf("%s",buffer);
			
			write(*to_server,buffer,BUFFER_SIZE);
			read(from_server,char_buf,BUFFER_SIZE);
			
			printf("[client] server's response: %s\n",char_buf);
			free(char_buf);
			free(buffer);
		}
	
}
