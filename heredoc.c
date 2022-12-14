#include "minishell.h"

int here_doc(char *delimiter)
{
	char *buffer;
	int here_doc_file;
	here_doc_file = open ("here_doc.temp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (here_doc_file < 0)
	{
		printf("probleme de creation de fichier");
		exit();
	}
	while(1)
	{
		write(0, "> ", 2);
		buffer = get_next_line(0);
		if (buffer && !ft_strncmp(buffer, delimiter, ft_strlen(delimiter)))
		{
			write(here_doc_file, buffer, ft_strlen(buffer))
			free(buffer);
		}
		else
			break;
	}
	return (here_doc_file);
}