C=gcc
FLAG=-Wall

all: set_policy

set_policy: set_policy.c 
	$(CC) $(FLAG) set_policy.c  -g -o set_policy


.PHONY: clean
clean:
	rm -f *.o client set_policy

