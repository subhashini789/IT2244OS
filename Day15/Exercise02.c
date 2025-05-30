/*Exercise 02:
First child: sleeps for 2 seconds, exits with status 2.
Second child: sleeps for 1 seconds, exits with status 1.
Parent: waits twice, and prints which child (by PID or exit code) finished first snd second.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status;

    printf("Parent process started. PID: %d\n", getpid());

    pid1 = fork(); // Create first child

    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        // First child process
        printf("First child process. PID: %d, sleeping for 2 seconds...\n", getpid());
        sleep(2);
        printf("First child exiting with status 2.\n");
        exit(2);
    }

    pid2 = fork(); // Create second child

    if (pid2 < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        // Second child process
        printf("Second child process. PID: %d, sleeping for 1 second...\n", getpid());
        sleep(1);
        printf("Second child exiting with status 1.\n");
        exit(1);
    }

    // Parent process
    for (int i = 0; i < 2; ++i) {
        pid_t finished_pid = wait(&status);
        if (WIFEXITED(status)) {
            printf("Child with PID %d exited with status %d\n", finished_pid, WEXITSTATUS(status));
        } else {
            printf("Child with PID %d did not exit normally.\n", finished_pid);
        }
    }

    printf("Parent process ending.\n");
    return 0;
}
