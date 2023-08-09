#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int n; // Number of child processes
    printf("Enter the number of child processes to create: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            // This code is executed by the child process
            printf("Child %d: PID = %d, Parent PID = %d\n", i, getpid(), getppid());
            exit(EXIT_SUCCESS);
        }
    }

    // This code is executed by the parent process
    for (int i = 1; i <= n; i++) {
        int status;
        pid_t terminated_pid = waitpid(0, &status, 0); // Waiting for any child process
        if (terminated_pid == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            printf("Child %d (PID = %d) exited with status %d\n", i, terminated_pid, WEXITSTATUS(status));
        }
    }

    return 0;
}
