/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:25:08 by agtshiba          #+#    #+#             */
/*   Updated: 2023/10/23 11:08:23 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//static int
//	ft_abs(int nbr)
//{
//	return ((nbr < 0) ? -nbr : nbr);
//}
// str[length++] = '0' + ft_abs(n % 10);

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln <= 9)
		ft_putchar_fd(ln + '0', fd);
	else
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putnbr_fd(ln % 10, fd);
	}
}

// int main()
// {
//     int n = -2147483649;
//     int fileDescriptor = 1;
//     ft_putnbr_fd(n, fileDescriptor);
// }
