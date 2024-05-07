#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <name>" << endl;
        return 1;
    }

    const char* name = argv[1];

    // Create a pipe for grep output
    int grep_pipefd[2];
    if (pipe(grep_pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    // Fork a child process for grep
    pid_t grep_pid = fork();

    if (grep_pid == -1) {
        perror("fork");
        return 1;
    } else if (grep_pid == 0) { // Child process for grep
        // Close the read end of the grep pipe
        close(grep_pipefd[0]);

        // Redirect stdout to write to the grep pipe
        dup2(grep_pipefd[1], STDOUT_FILENO);
        close(grep_pipefd[1]);

        // Execute grep command to find the line with the name
        execlp("grep", "grep", name, "phonebook.txt", NULL);
        perror("execlp grep");
        return 1;
    } else { // Parent process
        // Close the write end of the grep pipe
        close(grep_pipefd[1]);

        // Create a pipe for phone number extraction
        int phone_pipefd[2];
        if (pipe(phone_pipefd) == -1) {
            perror("pipe");
            return 1;
        }

        // Fork a child process for phone number extraction
        pid_t phone_pid = fork();

        if (phone_pid == -1) {
            perror("fork");
            return 1;
        } else if (phone_pid == 0) { // Child process for phone number extraction
            // Close the write end of the phone pipe
            close(phone_pipefd[1]);

            // Redirect stdin to read from the phone pipe
            dup2(phone_pipefd[0], STDIN_FILENO);
            close(phone_pipefd[0]);

            // Use awk to extract the phone number
            execlp("awk", "awk", "-F,", "{print $2}", NULL);
            perror("execlp awk");
            return 1;
        } else { // Parent process
            // Close the read end of the phone pipe
            close(phone_pipefd[0]);

            // Redirect the output of grep command to the phone pipe
            char buffer[4096];
            ssize_t bytesRead;
            while ((bytesRead = read(grep_pipefd[0], buffer, sizeof(buffer))) > 0) {
                write(phone_pipefd[1], buffer, bytesRead);
            }
            close(grep_pipefd[0]);
            close(phone_pipefd[1]);

            // Wait for the child process to finish
            waitpid(phone_pid, NULL, 0);
        }

        // Wait for the grep child process to finish
        waitpid(grep_pid, NULL, 0);
    }

    return 0;
}

