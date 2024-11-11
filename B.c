Q.2) Generate parent process to write unnamed pipe and will write into it. Also generate child process which will read from pipe.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pipe(pipefd);
    pid_t pid = fork();

    if (pid > 0) {
        close(pipefd[0]);
        char msg[] = "Message from parent process";
        write(pipefd[1], msg, strlen(msg) + 1);
        close(pipefd[1]);
        wait(NULL);
    } else {
        close(pipefd[1]);
        char buffer[100];
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Read from pipe: %s\n", buffer);
        close(pipefd[0]);
        exit(0);
    }
    return 0;
}


Output:
Read from pipe: Message from parent process