/*************************
Name: Josh Heigley
Question 1: Can both the child and parent access the file descriptor returned by open()?
Answer: Yes, both processes are able th acces the file descriptor and write or read from the file.
Question 2: What happens when they are writing to the file concurrently, i.e., at the same time?
Answer: From what I have seen, one process will write everything onto the file, and then the next process will write everything that it needs.
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
int desc = open("file.txt", O_WRONLY);
int rc = fork();
if (rc < 0) {
// fork failed
fprintf(stderr, "fork failed\n");
exit(1);
} else if (rc == 0) {
// child (new process)
write(desc, "hello I am child method\n", 24);
printf("Child wrote to file\n");
} else {
// parent goes down this path (main)
write(desc, "hello I am parent method\n", 25);
printf("Parent wrote to file\n");
}
close(desc);
return 0;
}
