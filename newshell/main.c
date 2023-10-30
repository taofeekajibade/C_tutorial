#include "main.h"

int main() {
	init_shell();

	char *line;
	char **args;
	int status = 1;

	do {
		line = read_input();
		if (line == NULL) {
			exit(EXIT_SUCCESS);
		}

		args = parse_input(line);
		if (args[0] != NULL) {
			execute_command(args);
		}

		free(line);
		free(args);
	} while (status);

	return EXIT_SUCCESS;
}
