/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:25:48 by agtshiba          #+#    #+#             */
/*   Updated: 2023/10/24 11:13:21 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j]
			&& i + j < len && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

// int main()
// {
//     const char *big = "Hello, World!";
//     const char *little = "World";
//     char *result = ft_strnstr(big, little, strlen(big));
//     if (result != NULL)
//     {
//         printf("Substring found: %s\n", result);
//     }
//     else
//     {
//         printf("Substring not found.\n");
//     }
//     return 0;
// }
