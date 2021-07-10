/*
Problem:
Now write a program that uses wait() to wait for the child process to finish in the parent. What does wait() return? What happens if you use wait() in the child?

*/

//Solution

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){
        printf("Inside the parent process with Pid : %d\n", (int)getpid());
        int rc = fork();
        if(rc<0){
                printf("fork Failed\n");
        }else if (rc==0){
                //int val = wait(NULL);
                //printf("%d\n",val);
                printf("Inside the child process with Pid : %d\n", (int)getpid());
                printf("child process\n");
        }else{
                int val = wait(NULL);
                printf("%d\n",val);
                printf("Parent process\n");
        }

}
