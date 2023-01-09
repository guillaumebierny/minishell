#include "minishell.h"

void	register_commands()
{
	add_command
}


void	register_all_command(t_command *cmd, char *s)
{
	char *saved_command;
	t_list_of_command lst_cmd;
	saved_command = s;
	while (s && s[i] )
	{
		lst_cmd.cmd =  add_command(cmd, s);
		ft_lstadd_back()
	}
}

t_command add_command(t_command *cmd, char *s)
{
	t_switch_quote sq;
	char *word;
	int i = -1;
	init_switch_quote(&sq);
	while (s[++i] && s[i] != '"|" '&& (!iswhite_space(s[i])
		|| (iswhite_space(s[i]) && in_quote(sq))))
	{
		make_the_switch(sq);
		redirection_case(cmd, s, &i);
		if (s[i] != '\'' && s[i] != '\"' )
			word = add_char_to_string(word, s[i])
	}
	cmd->cmd = put_string_into_tab(word);
	if s[i] == 

}

char **put_string_into_tab(char *s, char **tab)
{
	int tab_len;
	int j;
	char **new_tab = NULL;
	tab_len = -1;
	j = -1;
	if (tab)
	{
		while (tab[++tab_len])
			;
	}
	else
		tab_len = 0;
	new_tab = b_malloc((tab_len + 2) * sizeof(char *));
	copy_tab(new_tab, tab);
	new_tab[tab_len] = s;
	new_tab[tab_len + 1] = NULL;
	return (new_tab);
}

char *add_char_to_string(char *s, char c)
{
	size_t len;
	len = ft_strlen(s);
	char *new_string;
	new_string = b_malloc((len + 2) * sizeof(char));
	if (s)
	{
		ft_strlcpy(new_string, s, len);
		free(s);
	}
	new_string[len] = c;
	new_string[len + 1] = 0;
	return (new_string);
}