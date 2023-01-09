#include "minishell.h"

void skip_space(char **s)
{
	int i = -1;
	while ((*s)[++i] && iswhite_space((*s)[i]))
		;
	return (*s[i]);
}