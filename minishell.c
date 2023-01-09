#include "minishell.h"

void    dollarcase(char *s, char **envp, int i)
{
    int j;
    char *updated_string;
    if ((s[i + 1] >= 9 && s[i + 1] <= 13) || s[i + 1] == '')
        return ("\$");
    
    if (!(getenv(s)))
        return ("");
    
	return (replace_dollar(updated_string, s, j))
}


int single_quote_switch(int sqs, char *s)
{
    int i = -1;
	if (s == '\'')
	{
		if (sqs)
			sqs = 0;
		else
			sqs = 1;
	}
	while (s[++i])
	{
		if (s[i] == '\'')
			return (1);
	}
	return (0);
}

double_quote_switch(int dqs, char *s)
{
    int i = -1;
    if (s == '\'')
	{
		if (sqs)
			sqs = 0;
		else
			sqs = 1;
	}
	while (s[++i])
	{
		if (s[i] == '\'')
			return (1);
	}
	return (0);
}

t_parsed parsing(char *s, char **envp)
{
    int sqs = 0;
    int dqs = 0;
    char *final_string;
    int i = -1;
    t_list lst;
    while (s[++i])
    {
		
        if (single_quote_switch(s + i, sqs))
		{
			if (double_quote_switch(s + i, dqs))
			{
				dollarcase(s, i, envp);
				sla();
				dla();
                sra();
                dra();
        	}
			else
				perror("error: you have to put a seconde double quote");
        }
		else
			perror("error: you have to put a second single quote ");
    }
    return (final_string);
}

minishell(char **envp)
{
    char ***tab_parsed;
    int last_error;
    char *basic_input;
    char *parsedinput;
    t_all_gathered all_gathered;
    while (1)
    {
        basic_input = readline(prompt());
        add_history(basic_input);
        parsedinput = parsing(basic_input, envp);

    }
    return(0);
}

int main(int argc, char **argv, char **envp)
{  
    minishell(envp);
    return (0);
}

place_in_tab(char *s)
{
    int sqs = 0;
    int dqs = 0;
    int i = -1;
    char ***triple_tab;
    while (s[++i])
    {
        single_quote_switch(sqs, s + i);
        double_quote_switch(dqs, s + i);
        put_dollar();
    }
    return (triple_tab);
}

{
    switch_quote->double_q = 0;
    switch_quote->single_q = 0;
}



int is_quote_working(char *s)
{
    t_switch_quote switch_quote;
    int i;

    i = -1;
    init_switch_quote(&switch_quote);
    while (s[++i])
    {

        if (s[i] == '\'' && !switch_quote.double_q)
            switch_quote.single_q = (switch_quote.single_q + 1) % 2;
        if (s[i] == '\"' && !switch_quote.single_q)
            switch_quote.double_q = (switch_quote.double_q + 1) % 2;
    }
    if (switch_quote.double_q || switch_quote.single_q)
        return (1);
    return (0);
}

//check if an not handled operator is present
int is_operator_not_handled()
{
    if (&)

    if (||)

}


put_arg_in_tab(t_command *cmd, char *s)
{
    char *word;
    char *save;
    int i = -1;
    while (s[++i] && ft_strchr("|><&"))
    {
        deal_with_quote();
        if (*s == ' ' && cmd->quote->singleq)
            return (word);
        save = word;
        word = malloc(sizeof(char) * (i + 2));
        ft_strlcpy(word, save, ft_strlen(save));
        word[i] = s[i];
        word[i + 1] = 0;
    }
    return (word);
}