#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t my_pid;
	pid_t child_pid = 1;
	int i = 0;
	int status;
	char *argv[] = {"ls", "-l", "tmp/", NULL};

	my_pid = getpid();
	while (i <= 4 && (child_pid != 0))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			printf("error");
			return (1);
		}
		else if (child_pid != 0)
		{
			wait(&status);
		}
		i++;
	}
	if (child_pid == 0)
	{
		printf("ID child: %u\n\n ID father: %u\n", getpid(), getppid());
		execve(argv[0], argv, NULL);
		printf(" \n\n");
	}
	else
	{
		printf("%u I'm your father: %u\n", my_pid, child_pid);
	}
	return (0);
}