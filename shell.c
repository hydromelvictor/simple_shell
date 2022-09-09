#include "shell.h"
int main(void)
{
    term_t term = {NULL, NULL, NULL, NULL, NULL, 0};
    size_t n = 0, hub = 0, i;

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
        term.cmd_lines = cmd_args(term.line, ";");
        for (i = 0; term.cmd_lines[i] != NULL; i++)
        {
            term.argv = cmd_args(term.cmd_lines[i], " \t\r\n\a");
            if (cmd_sys(term) == 400)
            {
                free(term.line);
                free(term.envp);
                free(term.cmd_lines);
                free(term.argv);
                free(term.cmd);
                exit(term.status);
            }
            free(term.argv);
            free(term.cmd);
        }
        if (hub == 0)
        {
            printf("$ ");
        }
        
    }
    free(term.line);
    free(term.cmd_lines);
    free(term.envp);
    exit(term.status);
}
