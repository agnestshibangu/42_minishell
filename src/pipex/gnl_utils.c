/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:10:45 by agtshiba          #+#    #+#             */
/*   Updated: 2024/05/29 16:31:15 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../minishell.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	str = (char *)malloc(sizeof(*s) * (len + 1));
// 	if (str == 0)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			str[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	str[j] = 0;
// 	return (str);
// }

// char	*ft_strdup(const char *s)
// {
// 	size_t	len;
// 	size_t	i;
// 	char	*str;

// 	len = ft_strlen(s);
// 	str = (char *)malloc(sizeof(char) * (len + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i <= len)
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	return (str);
// }

// char	*ft_strchr(const char *s, int i)
// {
// 	while (*s)
// 	{
// 		if (*s == i)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (i == '\0')
// 		return ((char *)s);
// 	return (0);
//}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j] != '\0')
// 	{
// 		str[i + j] = s2[j];
// 		j++;
// 	}
// 	str[i + j] = '\0';
// 	return (str);
// }
