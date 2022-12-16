#include "minishell.h"

void lafonction(char *string)
{
    printf("voila ta string %s\n", string);
}

int   check_env_var(char *s,char **envp, int *j)
{
    int i = -1;
    while (envp[++i])
    {
        j = -1;
        while (envp[i][++(*j)] != '=' && s[*j] && s[*j] == envp[i][*j]);
        if (s[*j] == 0 && envp[i][*j] == '=')
            return (0);
    }
    return (1);
}

void    dollarcase(char *s, char **envp)
{
    int j;
    char *updated_string;
    if (check_env_var(s, envp, &j))
        perror("error");
	updated_string = s + j;
	replace_dollar(updated_string, s, j);
}

char *parsing(char *s, char **envp)
{
    char *final_string;
    int i = -1;
    while (s[++i])
    {
        single_quote_switch();
        double_quote_switch();
        dollarcase(envp);
        sla();
        rla();
        
        
    }
    return (final_string);
}

minishell(char **envp)
{
    int last_error;
    char *basic_input;
    char *parsedinput;
    while (1)
    {
        basic_input = readline("Minishell: ");
        history(basic_input);
        parsedinput = parsing(basic_input, envp);
    }
    return(0);
}

int main(int argc, char **argv, char **envp)
{  
    minishell(envp);
    return (0);
}