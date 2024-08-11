/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsion <thsion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:11:54 by thsion            #+#    #+#             */
/*   Updated: 2024/08/11 11:11:55 by thsion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int change_directory(char *str)
{
    char *path;

    if (!str || strcmp(str, "~") == 0)
    {
        printf("home directory :)");
        path = getenv("HOME");
        if (!path)
        {
            fprintf(stderr, "cd: HOME not set\n");
            return 1;
        }   
    }
    else
    {
        path = str;
    }

    if (chdir(path) != 0)
    {
        fprintf(stderr, "cd: %s: %s\n", path, strerror(errno));
        return 1;
    }
    setenv("OLDPWD", getenv("PWD"), 1);
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("changing \n");
        setenv("PWD", cwd, 1);
    }
    else
    {
        fprintf(stderr, "cd: error getting current directory: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}
