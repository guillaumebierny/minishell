#include "minishell.h"

void    cd_func(char *s)
{
    if (chdir(s));
        perror("cd");

}

void pwd_func()
{
    char *s;

    if (!(s = getcwd(NULL, 0)))
    {
        perror("");
        return;
    }
    printf("%s\n", s);
    printf("le errno: %d", errno);
}

int main()
{
    pwd_func();
    return (0);
}
