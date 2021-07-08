/***************************************************************************************************************************************
Problem:

Write a program that calls fork(). Before calling fork(), have the main process access a variable (e.g., x) and set its value to something (e.g., 100). 
What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x?
*****************************************************************************************************************************************/

//Solution


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
    int x = 100;
    printf("The intial value of x is %d\n", x);
    printf("Running the parent process with pid :%d\n", (int)getpid());
    //Forking a new process
    int rc = fork();
    
    if (rc < 0){
        // Fork has failed
        fprintf(stderr,"Fork Failed");
    }
    else if (rc==0){
        printf("Inside the chlid process with pid: %d\n", (int)getpid() );
        printf("The initial value of x in child is %d\n", x);
        x= 20;
        printf("The final value of x in child is %d\n", x);
    }else{
        printf("Inside the Parent process with pid: %d\n", (int)getpid() );
        printf("The initial value of x in parent is %d\n", x);
        x= 30;
        printf("The final value of x in parent is %d\n", x);
        
    }
    
}

/**************************************************************************************************************
Result

The intial value of x is 100
Running the parent process with pid :8622
Inside the Parent process with pid: 8622
The initial value of x in parent is 100
The final value of x in parent is 30
Inside the chlid process with pid: 8626
The initial value of x in child is 100
The final value of x in child is 20

**************************************************************************************************************/
