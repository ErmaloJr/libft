/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:24:08 by eramusho          #+#    #+#             */
/*   Updated: 2023/03/03 22:36:59 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	int				i;
	char			*str;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	if (!str)
		return (0);
	ft_strcpy(str, (char *)s1);
	len = ft_strlen(s1);
	ft_strcpy(&str[len], (char *)s2);
	return (str);
}
/*
int main(void)
{
	char *s = "";
	char *k = "Kim";

	ft_strjoin(s, k);
}
*/