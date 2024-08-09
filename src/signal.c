// #include "../minishell.h"
// # include <readline/readline.h>
// # include <readline/history.h>

// void signal_handler(void);
// void new_routine(int signal);



// void signal_handler(void)
// {
//     struct sigaction sa;

//     sa.sa_flags = SA_RESTART;
//     sa.sa_handler = new_routine;
//     sigemptyset(&sa.sa_mask);
//     sigaction(SIGINT, &sa, NULL);
//     signal(SIGQUIT, SIG_IGN);
// }

// void new_routine(int signal)
// {
//     if (signal == SIGINT)
//     {
//         printf("\n");
//         rl_replace_line("", 0);
//         rl_on_new_line();
//         rl_redisplay(); // Redisplay the prompt on a new line
//     }
// }
