#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

static int num_signal=0;

void signal_handler(int sig){
	if(sig==10){//SIGUSR1
	printf("\n prints %d sigint \n",num_signal);
	}
	if(sig==2){//SIGINT
	num_signal++;
	}		
}
		

int main(){
	
	printf("server pid: %d\n", getpid());	
	while(1){
	signal(SIGUSR1,signal_handler);
	signal(SIGINT,signal_handler);

	}
return 0;		
			
}
