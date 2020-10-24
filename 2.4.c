#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childProcess()
{
  printf("Child process => PPID=%d, PID=%d\n", getppid(), getpid());
}
 
void parentProcess()
 {
    printf("\nParent process => PID=%d \n", getpid());
    printf("Waiting for child processes to finish...\n");
    wait(NULL);
    printf("child process finished.\n");
}
void complete() {
    printf("Job is done!");
}

int main(void) {
    char name[10];
  for(int i = 0; i < 4; i++)
 { 
    pid_t pid = fork();
    
    if(pid == 0)
    {
        printf("What's your name? : ");
        scanf("%s", name);
        printf("Your name is %s \n", name);
        childProcess();
        exit(0);
    }
    else
    {
        parentProcess();
    }
  }
 
    complete();
    
  return EXIT_SUCCESS;
}
