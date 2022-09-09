#include "shell.h"
int main(void)
{
    term_t term = {NULL, NULL, NULL, NULL, 0};
    size_t n = 0, hub = 0;

    if (isatty(STDIN_FILENO) == 0)
    {
        hub = 1;
    }
    if (hub == 0)
    {
        printf("$ ");
    }
    
    while (getline(&term.line, &n, stdin) != EOF)
    {
        term.argv = cmd_args(term.line, " \t\r\n\a");
        if (cmd_sys(term) == 400)
        {
            exit(term.status);
        }
        if (hub == 0)
        {
            printf("$ ");
        }
    }
    free(term.argv);
    free(term.cmd);
    free(term.envp);
    free(term.line);
    exit(term.status);
}
