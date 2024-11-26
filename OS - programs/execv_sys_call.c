#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("Child process executing another program using execv...\n");
        char *path = "/bin/ls";
        char *args[] = {"ls", "-l", NULL};
        execv(path, args);
        perror("execv failed");
        exit(1);
    } else {
        printf("Parent process waiting for child to complete...\n");
        wait(NULL);
        printf("Child process finished.\n");
    }

    return 0;
}
