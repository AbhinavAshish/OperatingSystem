/*
Problem :

Write a program that opens a file (with the open() system call) and then calls fork() to create a new process.
Can both the child and parent access the file descriptor returned by open()?
What happens when they are writing to the file concurrently, i.e., at the same time?
*/


//Solution

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int main()
{
    int x = 100;
    printf("The intial value of x is %d\n", x);
    printf("Running the parent process with pid :%d\n", (int)getpid());
    //Forking a new process
    
    //close(STDOUT_FILENO); 
	int fd = open("data.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
	printf("The FD is %d\n", fd);
	char  buf[20] ;
	strcpy(buf, "This is  test\n");
    int nbytes = strlen(buf);
	write(fd,buf,nbytes);
	strcpy(buf, "Check this\n");
	nbytes = strlen(buf);
	write(fd,buf,nbytes);
	
    int rc = fork();
    
    if (rc < 0){
        // Fork has failed
        fprintf(stderr,"Fork Failed");
    }
    else if (rc==0){
        char new_buf[20];
        printf("running  the Child process : %d\n" ,(int)getpid());
        strcpy(new_buf, "Child process\n");
        nbytes = strlen(new_buf);
        write(fd,new_buf,nbytes);
        
        
    }else{
        //wait(NULL);
        printf("running  the parent process : %d\n" ,(int)getpid());
        char new_buf[20];
        strcpy(new_buf, "Parent process\n");
        nbytes = strlen(new_buf);
        write(fd,new_buf,nbytes);
    }
    close(fd);
}
