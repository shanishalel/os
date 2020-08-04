C=gcc
FLAG=-Wall

all: ques1

server: server.c 
	$(CC) $(FLAG) server.c  -g -o server
client: client.c 
	$(CC) $(FLAG) client.c  -g -o client

.PHONY: clean
clean:
	rm -f *.o client server

