#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]){
	pid_t pid=atoi(argv[1]);//convert from string to number
	if(kill(pid,0)==-1){//if kill fail he return -1
		//print what they ask for
		if(errno==ESRCH){
			printf("%d does not exist.\n", pid);
 		}
		else if(errno==EPERM){
			printf("%d exists but we have no permission.\n", pid);
		}
		
	}
	else{
		printf("%d exist.\n", pid);
	}
}
