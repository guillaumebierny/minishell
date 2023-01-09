#include "minishell.h"

void	redirection_case(t_command *cmd, char *s, int *i)
{
	if (s[*i] == '<' && s[(*i) + 1] == '<')
	{
		here_doc_case(cmd, i, s);
	}
	else if (s[*i] == '<' && s[(*i) + 1] == '>')
	{
		in_out_file_case();
	}
	else if (s[*i] == '>' && s[(*i) + 1] == '>')
	{
		append_case();
	}
	else if (s[(*i) + 1] == '>')
	{
		outfile_case(cmd, s, i);
	}
}



void in_out_file_case(t_command *cmd, char *s, int *i)
{
	char *word;
	(*i)++;
	if (cmd->outfile != 1)
		close(cmd->outfile);
	while (iswhite_space(s[++(*i)]))
		(*i)++;
	while (s[(*i)] && s[(*i)] != '"|" '&& (!iswhite_space(s[(*i)])
		|| (iswhite_space(s[(*i)]) && in_quote(sq))))
	{
		make_the_switch(sq);
		redirection_case(cmd, s, &(*i));
		if (s[(*i)] != '\'' && s[(*i)] != '\"' )
			word = add_char_to_string(word, s[(*i)]);
		++(*i);
	}
	if(!word)
	{
		word = b_malloc(1 * sizeof(char));
		word[0] = 0;
	}
	if (check_access_of_file(word, READ))
	{
		free(word):
		return (0);
	}
	cmd->outfile = open(word, O_CREAT | O_WRONLY | O_APPEND, 0644);
	free(word);
	if (cmd->outfile < 0)
		return (file_error()):
}

void outfile_case(t_command *cmd, char *s, int *i)
{
	char *word;
	if (cmd->outfile != 1)
		close(cmd->outfile);
	while (iswhite_space(s[++(*i)]))
		(*i)++;
	while (s[(*i)] && s[(*i)] != '"|" '&& (!iswhite_space(s[(*i)])
		|| (iswhite_space(s[(*i)]) && in_quote(sq))))
	{
		make_the_switch(sq);
		redirection_case(cmd, s, &(*i));
		if (s[(*i)] != '\'' && s[(*i)] != '\"' )
			word = add_char_to_string(word, s[(*i)]);
			(*i)++;
	}
	if(!word)
	{
		word = b_malloc(1 * sizeof(char));
		word[0] = 0;
	}
	if (check_access_of_file(word, READ))
	{
		free(word);
		return (0);
	}
	cmd->outfile = open(word, O_CREAT | O_WRONLY | O_APPEND, 0644);
	free(word);
	if (cmd->outfile < 0)
		return (file_error());
}

void	append_case(t_command *cmd, char *s, int *i)
{
	char *word;
	if (cmd->outfile != 1)
		close(cmd->outfile);
	while (iswhite_space(s[++(*i)]))
		(*i)++;
	while (s[++(*i)] && s[(*i)] != '"|" '&& (!iswhite_space(s[(*i)])
		|| (iswhite_space(s[(*i)]) && in_quote(sq))))
	{
		make_the_switch(sq);
		redirection_case(cmd, s, &(*i));
		if (s[(*i)] != '\'' && s[(*i)] != '\"' )
			word = add_char_to_string(word, s[(*i)]);
	}
	if(!word)
	{
		word = b_malloc(1 * sizeof(char));
		word[0] = 0;
	}
	if (check_access_of_file(word, READ))
	{
		free(word);
		return (0);
	}
	cmd->outfile = open(word, O_CREAT | O_WRONLY | O_APPEND, 0644);
	free(word);
	if (cmd->outfile < 0)
		return (file_error());
}

void	here_doc_case(t_command *cmd, int *i, char *s)
{
	t_switch_quote sq;
	char *word;
	init_switch_quote(sq);
	(*i)++;
	if (cmd->infile)
		cmd->infile = 0;
	while (iswhite_space(s[++(*i)]))
		(*i)++;
	while (s[++(*i)] && s[(*i)] != '"|" '&& (!iswhite_space(s[(*i)])
		|| (iswhite_space(s[(*i)]) && in_quote(sq))))
	{
		make_the_switch(sq);
		redirection_case(cmd, s, &(*i));
		if (s[(*i)] != '\'' && s[(*i)] != '\"' )
			word = add_char_to_string(word, s[(*i)]);
	}
	if (word)
		cmd->here_doc = word;
	else
	{
		cmd->here_doc = b_malloc(1 * sizeof(char));
		cmd->here_doc[0] = 0;
	}
}