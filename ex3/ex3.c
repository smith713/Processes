// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int ret = fork();
    int status;

    if(ret < 0) {
      printf("Child process creation failed");
      exit(1);
    } else if(ret == 0) {
      printf("hello\n");
    } else {
        while (waitpid (ret, &status, WNOHANG) == 0) {
           sleep(1);
        }
        printf("goodbye\n");
    }
    return 0;
}
