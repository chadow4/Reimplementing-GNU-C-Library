#include "mini_lib.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

extern char **environ;

int parseParams(char *command, char *args[]) {
    int argLen = 0;
    int argCount = 0;
    args[argCount] = mini_calloc(sizeof(char),1024);
    for (int i = 0; i < mini_strlen(command); i++) {
        if (command[i] == ' ') {
            args[argCount + 1] = mini_calloc(sizeof(char), 1024);
            args[argCount][argLen] = '\0';
            argCount++;
            argLen = 0;
        } else if (command[i] == '\n') {
            args[argCount][argLen] = '\0';
            args[argCount+1] = NULL;
            argCount++;
            return argCount;
        } else {
            args[argCount][argLen] = command[i];
            argLen++;
        }

    }

    return argCount;
}

void exec(char *commands[]) {
    if (mini_strcmp(commands[0], "exit") == 0)
        mini_exit();
    if (mini_strcmp(commands[0], "mini_cd") == 0) {
        // Check if the user provided a directory to change to
        if (commands[1] == NULL) {
            mini_printf("Error: No directory provided\n");
            return;
        }
        // Use chdir() to change the current working directory
        if (chdir(commands[1]) != 0) {
            mini_printf("Error: Unable to change directory\n");
        }
        return;
    }
    if (mini_strcmp(commands[0], "mini_env") == 0) {
        // Print the environment variables
        char **env = environ;
        while (*env != NULL) {
            mini_printf(*env);
            mini_printf("\n");
            env++;
        }
        return;
    }
    switch (fork()) {
        case -1:
            mini_exit();
            break;
        case 0:
            int result = execve(commands[0], commands, NULL);
            if (result == -1) {
                mini_printf(commands[0]);
                mini_printf(": command not found\n");
            }
            _exit(0);
            break;
        default:
            wait(NULL);
            break;
    }
}

int main(void) {


    while (1) {
        write(1, " $ ", 3);
        char *buffer = mini_calloc(sizeof(char), 1024);
        mini_scanf(buffer, 1024);
        char **newBuffer = mini_calloc(sizeof(char *), 10);

        int countArg = parseParams(buffer, newBuffer);

        if (countArg == 0) {
            continue;
        }

        exec(newBuffer);

        for (int i = 0; i < countArg; i++) {
            mini_free(newBuffer[i]);
        }

        mini_free(buffer);


    }


    return 0;


}