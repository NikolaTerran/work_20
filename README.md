# work_20
## Named Pipes
### Also known as FIFOs.
### Same as unnamed pipes except FIFOs have a name that can be used to identify them via different programs.
### Like unnamed pipes, FIFOS are unidirectional
''' 
mkfifo 
'''
## Shell command to make a FIFO

### Terminal A: $ cat mario
### Terminal B: $ cat > mario
### 	type stuff in TB + enter
### 	Quit one end the other end also quit
###		write end will wait for stdin
###		last message is not received
###		FIFO not exist on disk, size always 0
###   FIFO can write from 2 end but if you try to read from 2 end the read is scheduled by OS
### Remove FIFO during process it just becomes an unnamed pipe
### 	If you recreate the FIFO the unfinished process will not be interupted

## C FIFO function call
### mkfifo - <sys/types.h> <sys/stat.h>
### c function to create a FIFO
### returns 0 on sucess and -1 on failure
### Once created the FIFO acts like a * file

## Server & Client
### Server makes a pipe
### Client makes a pipe
### Client connects to the server pipe
### Client send a verification msg along with pipe name to server
### Server connects to the client pipe
### Server sends a verification msg

## Handshake
### A procedure to ensure that a connection has been established between 2 programs
### Both ends of the connection must verify that they can send and receive data to and from each other.

### 3 way handshake
### Client sends a message to the server
### Server sends a response to the client
### Clients sends a response back to the server

## Basic Server/Client design pattern
### 1. Set up
### 1.1 Server creates a FIFO(WELL KNOWN PIPE) and waits for a connection
### 1.2 Client creates a "private" FIFO (use PID)
### 2. Handshake
### 2.1 Client connects to the server and sends the private FIFO name, Client waits for a 
###     response from the server
### 2.2 Server receives client's message and removes the WKP.
### 2.3 Server connects to client FIFO, sending an initial acknowlegement message 
### 2.4 Client receives server's message, removes its private FIFO.
### 2.5 Client sends response to server.
### 3. Operation: Server and client send information back and forth.
### 4. Reset
### 4.1 Client exits, server closes any connections to the client.
### 4.2 Server recreates the WKP waits for another client.
##Forking server/client design pattern
###2. Handshake
###2.1. Client connects to server and sends the private FIFO name. Client waits for a response from the server. 
###2.2. Server receives client's message and forks off a subserver
###2.3. Server closes and removes WKP.
###2.4. Subserver connects to client FIFO, sending an initial acknowledgement message.
###3. Operation
###Server recreates WKP and waits for a new connection. Subserver and client send information back and forth.
###
###
###















