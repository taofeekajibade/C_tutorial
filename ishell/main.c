#include "main.h"
/**
 * main - the main function of the simple shell
 * @ac: argument 1
 * @argv: argument 2
 * Return: Always 0, success
 */
int main(int ac, char **argv)
{
	char *enter = "(ishell) £";
	char *usercmd;
	char *usercmd_cpy = NULL;
	char *delim = "\n";
	char *token;
	size_t n = 0;
	ssize_t char_count;
	ssize_t token_count = 0;
	int i;

	(void)ac; (void)argv;
	while (1)
	{
		printf("%s ", enter);
		char_count = getline(&usercmd, &n, stdin);
		if (char_count == -1)
		{
			printf("Exiting ishell...\n");
			return (-1);
		}

		usercmd_cpy = malloc(sizeof(char) *char_count);
		if (user_cpy == NULL)
		{
			perror("tsh: Failed to allocate memory..");
			return (-1);
			strcpy(usercmd_cpy, usercmd);

			token = strtok(usercmd, delim);
			while (token != NULL)
			{
				token_count++;
				token = strtok(NULL, delim);
			}
			token_count++;

			argv = malloc(sizeof(char *) * token_count);
			token = strtok(usercmd_cpy, delim);
			for (i = 0; token != NULL, i++)
			{
				argv[i] = malloc(sizeof(char) * strlen(token));
				strcpy(argv[i], token);

				token = strtok(NULL, delim);
			}
			argv[i] = NULL;

			printf("%s\n", usercmd);

			free(usercmd);
		}

		return (0);
	}
