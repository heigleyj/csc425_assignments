/*************************
Name: Josh Heigley
Question 1: can you make the make the child execute in its entirety before the parent without calling wait() in the parent?
Answer: Although there is no way to guarentee that the child will finish first without using wait, as it is up to the OS' scheduling sytem, using the sleep() to make the program 
wait a given time will almost certainly make the child  complete first.
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
int rc = fork();
if (rc < 0) {
// fork failed
fprintf(stderr, "fork failed\n");
exit(1);
} else if (rc == 0) {
// child (new process)
printf("hello\n");
} else {
// parent goes down this path (main)
sleep(1);
printf("goodbye\n");
}
return 0;
}

