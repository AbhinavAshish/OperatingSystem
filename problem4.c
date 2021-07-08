problem3	problem3.c	problem4	problem4.c	sammplels	samplels.c	template.c	test		test.c		wordcount.c
aabhinav-mac-1:cprograms abhinavashish$ vi problem4.c

/*
Problem:
Write a program that calls fork() and then calls some form of exec() to run the program /bin/ls. See if you can try all of the variants of exec(), including (on Linux) execl(), execle(), execlp(), execv(), execvp(), and execvpe(). Why do you think there are so many variants of the same basic call?

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
                printf("child process\n");
        }else{
                  char *myargs[2];
                  myargs[0] = strdup("/bin/ls");   // program: "ls"
                  myargs[1] = NULL; // argument: file to count
                  printf("Test");
                  execvp(myargs[0],myargs);
                  printf("Parent process\n");
        }

}
// For other exec Functions : https://www.geeksforgeeks.org/exec-family-of-functions-in-c/
~                                                                                              
