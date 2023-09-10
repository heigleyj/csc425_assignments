/*************************
Name: Josh Heigley
Question 1: What value is the variable in the child process?
Answer: The value will stay the same as it was unless it is changed after the fork, and will be the same as it is in the parent process unless it is changed in a section of program
that the parent process cannot enter.
Question 2: What happens to the variable when both the child and parent change the value of x?
Answer: The variable changes independantly of the parent and child when each change it to a different value in their own section of the program. It essentially becomes two different
variables that started off as the same.
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
int x = 100;
printf("Before Fork (value:%d)\n", (int) x);
int rc = fork();
if (rc < 0) {
// fork failed
fprintf(stderr, "fork failed\n");
exit(1);
} else if (rc == 0) {
// child (new process)
x += 50;
printf("child (value:%d)\n", (int) x);
} else {
// parent goes down this path (main)
x += 100;
printf("parent (value:%d)\n", (int) x);
}
return 0;
}
