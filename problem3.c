/*

Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent?

*/


//Solution

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

int main(){
        printf("Printing the pid of the parent: %d \n",(int)getpid());
        int rc = fork();
        if(rc<0){
                fprintf(stderr,"Fork failed for this process\n");

        }
        else if(rc==0){
                printf("hello\n");
        }else{
        //if you want to use wait uncomment the line below
        //wait(NULL);
        int fd = creat("data.txt",O_CREAT|O_WRONLY|O_TRUNC);
        remove("data.txt");
        printf("goodbye\n");

        }


}
/*Result:
Printing the pid of the parent: 23806
hello
goodbye
*/

