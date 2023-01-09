#include "minishell.h"


//return either 0 either 1 if not existing
void is_existing_env_var(char **envp, char *s)
{
	int i;
	int j;
	while (envp[i])
	{
		if(ft_strncmp(s, envp[i], ft_strlen(s)))
			return (0);
	}
	return (1);
}

create_env_var(char *s, char **envp)
{
	char **new_env;
	new_env = NULL;
	new_env = b_malloc((env_len(envp) + 2) * sizeof(char *));
	while (envp[i])
	{
		ft_strncmp(s,)
	}
	else
	{
		
	}
}


env_len(char **envp)
{
	int i;
	i = 0;
	if (!envp)
		return (0);
	while (envp[++i])
		;
	return (i);
	
}

void *b_malloc(size_t bytes)
{
	void *malloced;

	malloced = malloc(bytes);
	if (!malloced)
	{
		perror("minishell");
		exit(1);
	}
	return (malloced);
}

char *replace_env_var(char *s, char **envp, char *key_env)
{
	char *new_s;

	if (is_existing_env_var(envp, key_env))
	{
		new_s = ft_substr_cat(new_s,)
	}
}


