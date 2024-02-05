/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:47:22 by eramusho          #+#    #+#             */
/*   Updated: 2022/12/25 12:08:10 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_malloc(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (start > ft_strlen (s))
		str = malloc(1);
	else if (len + (size_t)start > ft_strlen (s))
		str = malloc((ft_strlen (s) - start) + 1);
	else
		str = malloc(len + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	str = ft_malloc(s, start, len);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
