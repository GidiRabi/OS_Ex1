#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " \"full name,phone number\"" << endl;
        return 1;
    }

    // Print length of input string before removing newline characters
    cout << "Length of input string before removing newline characters: " << strlen(argv[1]) << endl;

    // Remove trailing newline character if present
    char* input = argv[1];
    size_t input_len = strlen(input);
    if (input_len > 0 && input[input_len - 1] == '\n') {
        input[input_len - 1] = '\0';
    }

    // Print length of input string after removing newline characters
    cout << "Length of input string after removing newline characters: " << strlen(input) << endl;

    // Create a pipe
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    // Fork a child process for awk
    pid_t awk_pid = fork();

    if (awk_pid == -1) {
        perror("fork");
        return 1;
    } else if (awk_pid == 0) { // Child process for awk
        // Close the read end of the pipe
        close(pipefd[0]);
        cout << "AWK Child process: Redirecting stdout to pipe" << endl;

        // Redirect stdout to write to the pipe
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
            perror("dup2");
            return 1;
        }
        close(pipefd[1]);

        // Execute awk command to print the input
        cout << "AWK Child process: Executing awk" << endl;
        execlp("awk", "awk", "{print $0}", NULL);
        perror("execlp awk");
        return 1;
    }

    // Close the write end of the pipe in the parent process
    close(pipefd[1]);
    cout << "Parent process: Closed write end of pipe" << endl;

    // Fork another child process for sh
    pid_t sh_pid = fork();

    if (sh_pid == -1) {
        perror("fork");
        return 1;
    } else if (sh_pid == 0) { // Child process for sh
        // Redirect stdin to read from the pipe
        if (dup2(pipefd[0], STDIN_FILENO) == -1) {
            perror("dup2");
            return 1;
        }
        close(pipefd[0]);
        cout << "SH Child process: Redirecting stdin from pipe" << endl;

        // Execute sh command to append to file
        cout << "SH Child process: Executing cat and appending to phonebook.txt" << endl;
        execlp("/bin/sh", "sh", "-c", "cat >> phonebook.txt", NULL);
        perror("execlp sh");
        return 1;
    }

    // Close the read end of the pipe in the parent process
    close(pipefd[0]);
    cout << "Parent process: Closed read end of pipe" << endl;

    // Wait for both child processes to finish
    waitpid(awk_pid, NULL, 0);
    cout << "Parent process: Waited for AWK child process" << endl;
    waitpid(sh_pid, NULL, 0);
    cout << "Parent process: Waited for SH child process" << endl;

    return 0;
}

