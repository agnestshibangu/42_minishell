/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:25:05 by agtshiba          #+#    #+#             */
/*   Updated: 2023/10/20 15:44:14 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}
// #include "libft.h"
// void	ft_putendl_fd(char *s, int fd)
// {
// 	int	i;
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	write(fd, s, i);
// 	write(fd, "\n", 1);
// }
