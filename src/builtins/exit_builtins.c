#include "../../minishell.h"

void handle_exit(char *input) {
    if (ft_strncmp(input, "exit", 4) == 0) {
        printf("Exiting shell...\n");
        exit(0);  
    }
}