#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ftw.h>

/* the function pass all the tree file in recursive way and prints for each file / lib : 
type, number of inode and name. if the lib contains soft link-ignore */
static int recursive_pass (const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf){
	if(tflag==FTW_SL) { return 0;} //if soft-link
	if(tflag==FTW_D || tflag==FTW_DNR ){ printf ("D ");}//directory
	else if(tflag == FTW_F){printf("F ");} //file 
	else{ return 0;}
	printf("%ld %s \n", sb->st_ino, fpath+ftwbuf->base);
	return 0;
}

int main(int argc, char*argv[]){

	nftw(argv[1],recursive_pass, 30, FTW_PHYS); //FTW_PHYS to occur the FTW_SL
	exit(EXIT_SUCCESS);
} 
