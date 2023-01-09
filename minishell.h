#ifndef MINISHELL_H
# define MINISHELL_H


#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"

enum e_file_access
{
	READ,
	WRITE,
	BOTH
};


typedef struct s_switch_quote
{
	int	single_q;
	int	double_q;
}		t_switch_quote;

typedef struct s_command
{
	char **cmd;
	char *here_doc;
	int infile;
	int outfile;
	t_switch_quote sq;
}	t_command;


typedef struct s_list_of_command
{
	struct s_command	*cmd;
	struct s_list_of_command	*next;
}			t_list_of_command;

typedef struct s_all_gathered
{
	t_list_of_command list_of_command;
}				t_all_gathered;	




void    init_switch_quote(t_switch_quote *switch_quote);
void skip_space(char **s);
int	iswhite_space(char c);
int in_quote(t_switch_quote sq);
void *b_malloc(size_t bytes);


#endif