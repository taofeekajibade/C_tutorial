#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void init_shell() {
	int interactive = 1; // Assume interactive mode by default

	if (!isatty(STDIN_FILENO)) {
		interactive = 0;
	}

	if (interactive) {
		// Interactive mode, display shell prompt
		write(STDOUT_FILENO, "Shell$ ", 7);
	}
}
