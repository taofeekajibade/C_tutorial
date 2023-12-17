#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

/* Function to display the shell prompt*/
void displayPrompt() {
	printf("#$ ");
}

/* Function to read a line of input from the user*/
char* readInput() {
	char* input = NULL;
	size_t bufsize = 0;
	getline(&input, &bufsize, stdin);
	return input;
}

/* Function to tokenize user input into an array of arguments*/
void tokenizeInput(char* input, int* ac, char*** args) {
	char* token = strtok(input, " ");
	*ac = 0;
	*args = malloc(sizeof(char*));

	while (token != NULL) {
		*args = realloc(*args, ((*ac) + 1) * sizeof(char*));
		(*args)[(*ac)] = token;
		(*ac)++;
		token = strtok(NULL, " ");
	}

	*args = realloc(*args, ((*ac) + 1) * sizeof(char*));
	(*args)[(*ac)] = NULL;
}

/* Function to execute a command*/
void executeCommand(int ac, char** args, char** env) {
	/* Create a child process*/
	pid_t pid = fork();

	if (pid < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		/* In the child process*/

		/* Execute the command with the specified environment*/
		if (execve(args[0], args, env) == -1) {
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	} else {
		/* In the parent process, wait for the child to complete*/
		int status;
		waitpid(pid, &status, 0);

		if (WIFEXITED(status)) {
			int exit_status = WEXITSTATUS(status);
			if (exit_status != 0) {
				printf("%s: Command not found\n", args[0]);
			}
		}
	}
}

int main(int ac, char **args, char **env) {
	while (1) {
		displayPrompt();
		char* input = readInput();

		/* Remove the newline character from the end of the input*/
		input[strcspn(input, "\n")] = '\0';

		/* Check if the input is not empty*/
		if (strlen(input) > 0) {
			int ac;
			char** cmd_args;

			tokenizeInput(input, &ac, &cmd_args);

			if (ac > 0) {
				executeCommand(ac, cmd_args, env);
			}

			free(cmd_args);
		}

		free(input);
	}

	return 0;
}
