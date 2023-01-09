
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd;
	int fd2;
	fd = open("prout", O_RDONLY);
	if (!fd)
	{
		printf("fait chie");
		return (1);
	}
	fd2 = open("smurfs", O_CREAT | O_RDWR |O_TRUNC, 0644);
	if (!fd2)
	{
		printf("probleme avec fd2");
		return (0);
	}
	dup2(fd2, STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(fd);
	char *dlist[] = {"grep", "bonjour", "salut", "coucou", NULL};
	execvp("grep", dlist);
	printf("y a eu une erreur\n");
	return (0);
}