#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char **argv) {
    int pipefd[2];
    pid_t pid1, pid2;
    int outfile;

    if (argc < 4 || strcmp(argv[2], "|") != 0) {
        write(2, "Usage: ./program cmd1 \"|\" cmd2\n", 31);
        return 1;
    }

    if (pipe(pipefd) < 0) {
        perror("pipe");
        return 1;
    }

    pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        return 1;
    }

    if (pid1 == 0) { // First child (ls)
        close(pipefd[0]);  // Close read end
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to pipe
        close(pipefd[1]);
        execlp(argv[1], argv[1], NULL);
        perror("execlp");
        return 1;
    }

    pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        return 1;
    }

    if (pid2 == 0) { // Second child (grep file.txt)
        close(pipefd[1]);  // Close write end
        dup2(pipefd[0], STDIN_FILENO); // Redirect stdin from pipe
        close(pipefd[0]);
        execlp(argv[3], argv[3], NULL);
        perror("execlp");
        return 1;
    }

    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    outfile = open("outfile", O_WRONLY | O_TRUNC);
    if (outfile < 0) {
        perror("open");
        return 1;
    }
    write(outfile, "Done\n", 5);
    close(outfile);

    return 0;
}
