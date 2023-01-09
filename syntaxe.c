#include "minishell.h"


in_quote(t_switch_quote sq)
{
	if (sq.single_q)
		return (1);
	if (sq.double_q)
		return (1);
	return (0);
}



int	iswhite_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}


check_beginning(char *s, int *i)
{
	while (iswhite_space(s[++(*i)]))
		;
	if (ft_strchr("|()", s[(*i)]))
	{
		printf("probleme de syntaxe");
		return (1);
	}
	return (0);

}


int check_left(char *s)
{
	if (*s == '<')
		return (erreur_de_syntaxe());
	if (*s == '>')
	{
		skip_space(&s);
		if (ft_strchr("<>|", s))
			return (erreur_de_syntaxe());
		return (0);
	}
	skip_space(&s);
	if (ft_strchr("<>|", s))
		return (erreur_de_syntaxe());	
	return (0);
}

int check_right(char *s)
{
	if (ft_strchr("<>", *s))
	{
		skip_space(&s);
		if (ft_strchr("<>|", s))
			return (erreur_de_syntaxe());
		return (0);
	}
	skip_space(&s);
	if (ft_strchr("<>|", s))
		return (erreur_de_syntaxe());
	return (0);
}

int	check_syntaxe_redirection(char *s)
{
	if (*s == '>')
		return (check_left());
	if (*s == '<')
		return (check_right());
	return (0);
	
}

int	check_syntax(char *s)
{
	int i = -1;
	t_switch_quote sq;
	init_switch(sq);

	check_beginning(s, &i);
	while (s)
	{
		make_the_switch(s, &sq);
		if (!in_quote(sq) && *s == '&()')
		{
			printf("probleme de syntaxe");
		}
		check_syntaxe_redirection(s + i);
	}
	if (in_quote(sq))
	{
		printf("quote non ferme");
		return (1);
	}
	return (0);
}

int	erreur_de_syntaxe()
{
	printf("erreur de syntaxe");
	return (1);
}