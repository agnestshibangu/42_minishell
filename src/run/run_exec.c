#include "../../minishell.h"


void    run_exec(char *command, t_tabenv *tabenv)
{
    exec(command, tabenv->env_vars);
}

// void    fill_struct(char *command, t_node *t_exec_node)
// {
//     exec_node->command = command;

// }

// void    run_exec(t_node *t_exec_node, t_tabenv *tabenv)
// {
//     char *every_path;


//     if (exec_node->is_builtin == true)
//         run_builtin(exec_node->command, tabenv->env_vars);
//     else
//     {
//         exec(exec_node->command, tabenv->env_vars);
//         //every_path = get_every_path(tabenv->env_vars, exec_node->command);
//     }
// }