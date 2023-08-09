#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void){
	printf("Hello World!\n");
	fork();
	printf("I am after fork\n");
	printf("\t I am process %d.\n",getpid());
}
