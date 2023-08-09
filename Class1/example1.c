#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main(){
           printf("My process Id is %d\n",getpid());
           printf("My Parent process Id is %d\n",getppid());
}  

