/*************************
Name: Josh Heigley
Question 1: What does wait() return?
Answer: wait() returns the PID of the child process.
Question 2: What happens if you use wait() in the child?
Anwer: This causes the wait() function to throw an error, as the child cannot wait for the parent, and returns -1.
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
int rc = fork();
if (rc < 0) {
// fork failed
fprintf(stderr, "fork failed\n");
exit(1);
} else if (rc == 0) {
// child (new process)
//int waitval = wait(NULL);
printf("Child\n"); //%d\n", (int) waitval);
} else {
// parent goes down this path (main)
int waitval = wait(NULL);
printf("Parent\n%d\n", (int) waitval);
}
return 0;
}
