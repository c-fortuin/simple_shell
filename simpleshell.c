#include "shell.h"

#define MAX_COMMAND_LENGTH 100

void execute_command(char* command)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		fprintf(stderr, "Fork error\n");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execlp(command, command, NULL) == -1)
		{
			fprintf(stderr, "Command not found\n");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}

/**
 * main - Main funstion of shell
 */

int main()
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("$ ");

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\nExiting shell...\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		execute_command(command);
	}

	return (0);
}
