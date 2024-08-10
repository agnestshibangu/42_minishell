/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:24:47 by agtshiba          #+#    #+#             */
/*   Updated: 2023/10/20 15:15:57 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}
// int main()
// {
//     char source[] = "hello world";
//     char destination[20];
//     printf("je suis la partie strcpy\n");
//     printf("je suis la destination : %s\n", destination);
//     ft_memcpy(destination, source, 8);
//     printf("destination : %s\n", destination);
//     memcpy(destination, source, 8);
//     printf("destination : %s\n", destination);
//     return 0;
// }
