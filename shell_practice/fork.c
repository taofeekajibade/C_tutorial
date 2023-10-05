#include "main.h"

/**
 * builtin_code - Array of builtin commands
 * Return: string
 */
char *builtin_code[] = 
{
	"cd",
	"exit",
	"env"
};

/**
 * builtin_fun - Array of corresponding builtin functions
 */
int (*builtin_func[])(char **) =
{
	&handle_cd,
	&handle_exit,
	&print_env
};

/**
 * builtin_select - selects the right builtins
 * Returns: integer
 */
int builtin_select(void)
{
	return sizeof(builtin_code) / sizeof(char *);
}

/**
 * fork_process - start a process
 * @argv: user commands
 * Return: 0 on success, or 1 on failure
 */
int fork_process(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("hsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("hsh");
	}
	else
	{
		do 
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
/**
 * execute_cmd - executes user commands
 * @argv: user commands
 * Return: processed parameters
 */
int execute_cmd(char **argv)
{
	int i;

	if (argv[0] == NULL)
	{
		return (-1);
	}
	for (i = 0; i < builtin_select(); i++)
	{
		if (strcmp(argv[0], builtin_code[i]) == 0)
		{
			return (*builtin_func[i])(argv);
		}
	}
	return (fork_process(argv));
}
