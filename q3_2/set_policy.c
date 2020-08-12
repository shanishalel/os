#define _GNU_SOURCE//if and def
#include <sched.h>//for sched_param
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <pthread.h>
#include <errno.h> //for the error
#include <linux/types.h>
#include <sys/syscall.h> //for sys
#include <time.h> //for the time

/*SCHED_OTHER =0
SCHED_FIFO=1
SCHED_RR=2
SCHED_IDLE=5*/


//for sched_setattr

#ifdef __x86_64__
#define __NR_sched_setattr      314
#endif

#ifdef __i386__
#define __NR_sched_setattr      351
#endif

#ifdef __arm__
#define __NR_sched_setattr      380
#endif


struct sched_attr {
    __u32 size;

    __u32 sched_policy;
    __u64 sched_flags;

    /* SCHED_NORMAL, SCHED_BATCH */
    __s32 sched_nice;

    /* SCHED_FIFO, SCHED_RR */
    __u32 sched_priority;

    /* SCHED_DEADLINE */
    __u64 sched_runtime;
    __u64 sched_deadline;
    __u64 sched_period;
};

//set attr
int sched_setattr(pid_t pid,const struct sched_attr *attr,unsigned int flags)
{
    return syscall(__NR_sched_setattr, pid, attr, flags);
}


/* set policy getting numbers the first is the policy number the secound is priority*/
int main(int argc, char *argv[]){
int policy=atoi(argv[1]);
int priority=atoi(argv[2]);

pid_t pid_num=getpid();
printf("pid : %d\n", pid_num);
printf("policy : %d\n", policy);
printf("priority : %d\n", priority);



struct sched_param s;
if(policy==SCHED_DEADLINE){
	struct sched_attr s_a;
	//set
	s_a.size=sizeof(s_a);
	s_a.sched_policy=SCHED_DEADLINE;
	s_a.sched_flags=0;
	s_a.sched_nice=0;
	s_a.sched_priority=priority;
	//by kernel web - creates 10ms/30ms reservation
	s_a.sched_runtime=10*1000*1000;
	s_a.sched_deadline=30*1000*1000;
	s_a.sched_period=30*1000*1000;
	sched_setattr(getpid(), &s_a,0);

}
else{//sched_param
	s.sched_priority=priority;
	if(sched_setscheduler(0,policy,&s)==-1){ //set the parameters in s
		//the error that we can get 
		if(errno==EPERM)printf("EPERM error\n");
		if(errno==EINVAL)printf("EINVAL error\n");
		if(errno==ESRCH)printf("ESRCH error\n");
	}
	
}
while(1){};

}

