/*************************
Name: Josh Heigley
Question 1:  Why do you think there are so many variants of the same basic call(exec)?
Answer: There are many different  varients of the exec() system call because there are many different use cases where using one is more optimal than using the other. The difference 
seems to be mainly in the way that arguments are passed and the way that the path to the file is reached.
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
execl("/bin/ls", "ls", NULL);
printf("This should not print\n");
} else {
// parent goes down this path (main)
printf("Parent\n");
}
return 0;
}
