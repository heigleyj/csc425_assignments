/*************************
Name: Josh Heigley
Question 1: When would waitpid() be useful?
Anwer: waitpid() would be useful if you were to run a program that made many child processes, and you wanted to wait for one specific child process to return before completing the 
parent process.
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
int status;
int rc = fork();
if (rc < 0) {
// fork failed
fprintf(stderr, "fork failed\n");
exit(1);
} else if (rc == 0) {
// child (new process)
printf("Child\n");
} else {
// parent goes down this path (main)
int waitval = waitpid(rc, &status, 0);
printf("Parent\n%d\n", (int) waitval);
}
return 0;
}
