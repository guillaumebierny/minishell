#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("pas le bon nombre d'arguments");
		return (0);
	}
	char *s = getenv(argv[1]);
	if (s)
		printf("%s\n", s);
	else
		printf("la variable %s n'existe pas\n", argv[1]);
	return (0);
}