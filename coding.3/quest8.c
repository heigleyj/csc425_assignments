/*************************
Name: Josh Heigley
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd[2];

        // pipe created
    if (pipe(pipefd) == -1) {
        printf("pipe failed\n");
        exit(1);
    }
        // first child is made
    int rc = fork();

    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if (rc == 0) {
        // first child
        close(pipefd[0]); // Close reading end of pipe

        // Redirect stdout to the writing end of pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]); // Close writing end of pipe

        // this goes to child 2 instead of to screen
        printf("Child 1: Sending data to Child 2\n");

    } else {
        // second child is made
        int rc1 = fork();

        if (rc1 < 0) {
            // fork failed
            fprintf(stderr, "fork failed\n");
            exit(1);

        } else if (rc1 == 0) {
            // second child
            close(pipefd[1]); // Close writing end of pipe

            // Redirect stdin to reading end of pipe
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]); // Close reading end of pipe

            // Reads and prints data
            char data[100];
            fgets(data, sizeof(data), stdin);
            printf("Child 2 received: %s", data);
        }
    }

    return 0;
}
