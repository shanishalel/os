#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]){

	int pid=atoi(argv[1]);
	int signal_type=atoi(argv[2]);
	int sigint_num=atoi(argv[3]);	


	if(signal_type!=2 && signal_type!=10){
		exit(0);	
	}
	
	for(int i=0;i<sigint_num;i++){
		kill(pid,signal_type);	
	}

		
}

