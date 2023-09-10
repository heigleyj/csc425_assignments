/*************************
Name: Josh Heigley
Question 1: What happens if the child calls printf() to print some output after closing the descriptor?
Answer: This causes the child to be unable to do any output operations, so the print command does not work.
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
int rc = fork();
if (rc < 0) {
// fork failed
fprintf(stderr, "fork failed\n");
exit(1);
} else if (rc == 0) {
// child (new process)
close(STDOUT_FILENO);
printf("Child\n");
} else {
// parent goes down this path (main)
printf("Parent\n");
}
return 0;
}
