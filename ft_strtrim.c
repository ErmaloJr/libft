/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:56:03 by eramusho          #+#    #+#             */
/*   Updated: 2022/12/25 10:34:18 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int	ft_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1);
	while (i != 0 && ft_strchr(set, s1[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				start;
	int				end;
	size_t			len;
	char			*str;

	if (!set || !s1)
		return (0);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	len = (end - start) + 1;
	if (start > end || (start == 0 && end == 0))
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1 + start, len);
	str[len] = '\0';
	return (str);
}
