#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(){
         if(fork() == 0){
                 printf("I am a child.\n");
          }
          else{
                 printf("I am a parent.\n");
           }

}
