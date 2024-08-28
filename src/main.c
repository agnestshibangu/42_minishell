/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:11:36 by thsion            #+#    #+#             */
/*   Updated: 2024/08/28 15:37:28 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int g_status;

void 	show_prompt(t_data *data)
{
	char *input;
    t_node  *final_node;

	while (1)
	{
		signal_handler();
		input = readline("minishell$ ");
		if (check_empty_input(input))
		{
			add_history(input);
            final_node = starting_tree(input, data);
            printf("%d\n", final_node->type);
		} 
	}
}

int main(int ac, char **av, char **envp)
{
	t_data data;

	(void)av;
	if (ac > 1)
		printf("🚫 Minishell doesn't take arguments. Still launching Minishell ... 🚫");
	init_env_tab(&data, envp);
	if (!data.env_vars)
		return (1);
	show_prompt(&data);
	free_minishell(&data);
	return (0);
}
