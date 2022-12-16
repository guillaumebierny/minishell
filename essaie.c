#include "minishell.h"

// int main()
// {
//     char *s;
//     while (1)
//     {
//         s = readline("minishell: ");
//         printf("%s\n", s);
        
//     }
// }

int main()
{
    DIR *dir;
    struct dirent *sd;
    if (!(dir = opendir(".")))
    {
        perror("dir not found");
        exit(1);
    }
    while ((sd = readdir(dir)))
        printf("%s\n", sd->d_name);
    closedir(dir);
    chdir("../..");
    printf("\n\nonchange de dir\n\n");
    if (!(dir = opendir(".")))
    {
        perror("dir not found");
        exit(1);
    }
    while ((sd = readdir(dir)))
        printf("%s\n", sd->d_name);
    closedir(dir);
    return (0);
}
