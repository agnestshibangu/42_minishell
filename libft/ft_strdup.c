/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:25:29 by agtshiba          #+#    #+#             */
/*   Updated: 2023/10/23 11:50:07 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		length;
	char	*strcpy;

	length = 0;
	while (s1[length])
		length++;
	strcpy = malloc(length + 1);
	if (strcpy != NULL)
	{
		i = 0;
		while (s1[i])
		{
			strcpy[i] = s1[i];
			i++;
		}
		strcpy[i] = '\0';
	}
	return (strcpy);
}

// #include <stdio.h>
// int main()
// {
//     const char *str = "coucou";
//     printf("%s", ft_strdup(str));
// }
