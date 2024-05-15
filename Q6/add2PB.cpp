#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments are provided
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " \"<name>,<phone number>\" " << endl;
        return 1;
    }

    // Open the phonebook file, create it if it doesn't exist
    int fileDescriptor = open("phonebook.txt", O_RDWR | O_APPEND | O_CREAT, 0644);

    // Check if the file was opened successfully
    if (fileDescriptor == -1)
    {
        perror("open");
        return 1;
    }

    // Seek to the end of the file
    off_t end = lseek(fileDescriptor, 0, SEEK_END);
    if (end == -1)
    {
        perror("lseek");
        return 1;
    }

    // If the file is not empty, check the last character
    if (end != 0)
    {
        // Seek to the position of the last character
        off_t lastCharPos = lseek(fileDescriptor, -1, SEEK_CUR);
        if (lastCharPos == -1)
        {
            perror("lseek");
            return 1;
        }

        // Read the last character
        char lastChar;
        ssize_t numRead = read(fileDescriptor, &lastChar, 1);
        if (numRead == -1)
        {
            perror("read");
            return 1;
        }

        // If the last character is not a newline, append a newline
        if (lastChar != '\n')
        {
            write(fileDescriptor, "\n", 1);
        }
    }

    // Iterate over the command line arguments
    for (int i = 1; i < argc; i++)
    {
        // Create a child process
        int pid1;
        if ((pid1 = fork()) == 0)
        {
            // Redirect the output of the process to the file
            dup2(fileDescriptor, STDOUT_FILENO);
            close(fileDescriptor);

            // Execute the echo command with the argument
            if (i == argc - 1)
            {
                execlp("echo", "echo", argv[i], NULL);
            }
            else
            {
                execlp("echo", "echo", "-n", argv[i], "", NULL);
            }
            perror("execlp");
            return 1;
        }
        else if (pid1 == -1)
        {
            perror("fork");
            return 1;
        }
        else
        {
            // Wait for the child process to finish
            waitpid(pid1, NULL, 0);
        }
    }

    return 0;
}