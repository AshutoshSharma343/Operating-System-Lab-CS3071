#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void){
	
	printf("Here I am just before first fork statement\n");
        fork();
	printf("Here I am just after first fork statement\n");
        fork();
	printf("Here, I am just  after second fork statement\n");
	fork();
	printf("Here i am just after third fork statemnt\n");
	printf("Hello Wolrd from process %d!\n",getpid());

}

