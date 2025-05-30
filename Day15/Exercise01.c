/*Exercise:
First child: Slept for 1 second.
Second child: Slept for 3 seconds.
Parent: Both children have finished.*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status;

    printf("Parent process started. PID: %d\n", getpid());

    pid1 = fork(); // First child

    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        // First child
        printf("First child started. PID: %d\n", getpid());
        sleep(1);
        printf("First child finished sleeping 1 second.\n");
        exit(0);
    }

    pid2 = fork(); // Second child

    if (pid2 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        // Second child
        printf("Second child started. PID: %d\n", getpid());
        sleep(3);
        printf("Second child finished sleeping 3 seconds.\n");
        exit(0);
    }

    // Parent waits for both children
    wait(&status);
    wait(&status);

    printf("Parent: Both children have finished.\n");
    return 0;
}
