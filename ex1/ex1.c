// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    int x = 100;
    pid = fork();
    if(pid < 0) {
      printf("Child process creation failed\n");
    } else if(pid == 0) {
      printf("Child process: x = %i\n",x);
      x += 5;
      printf("Updated child process: x = %i\n",x);
    } else {
      printf("Parent process: x = %i\n",x);
      x += 10;
      printf("Updated parent process: x = %i\n",x);
    }
    return 0;
}
