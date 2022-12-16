#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = -1;
	int j = 0;
	int x = 0;
	if (argc < 2)
	{
		printf("vous n'avez pas rentre d'input");
		return (0);
	}
	while (argv[++x])
	{	
		i = -1;
		while (argv[x][++i])
		{
			if (argv[x][i] >= 'a' && argv[x][i] <= 'z')
				j++;
		}
	}
	printf("il y a en tout %d lettres pour %d mots dans l'input", j, x - 1);
	return (0);
}

char *s = "bonjour";
int scc = 0;
while (s)
{
	if (s* == '\'')
	{
		if (scc)
			scc = 0;
		else
			scc = 1;
	}
	if (scc && s* == '$')
	{
		change_to_env_variable();
	}
}