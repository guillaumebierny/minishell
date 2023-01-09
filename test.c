#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	char *arg[] = {"ls", ">", "prout", NULL};
	execvp("ls", arg);
	return (0);
}
