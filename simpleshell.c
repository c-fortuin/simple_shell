#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * main - Main funstion of shell
 */

int main()
{
	char command[MAX_COMMAND_LENGTH];
	char prompt[] = "simple_shell> ";

	while (1)
	{
		printf("%s", prompt);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execlp(command, command, NULL) == -1)
			{
				perror("exelp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}

			if (WIFEXITED(status))
			{
				int exit_status = WEXITSTATUS(status);

				if (exit_status != 0)
				{
					fprintf(stderr, "Command '%s' exited with status %d\n", command, exit_status);
				}
				else if (WIFSIGNALED(status))
				{
					int signal_number = WTERMSIG(status);

					fprintf(stderr, "Command '%s' terminated by signal %d\n", command, signal_number);
				}
			}
		}
		return 0;
	}
