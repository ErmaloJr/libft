/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:34:44 by eramusho          #+#    #+#             */
/*   Updated: 2022/12/25 10:31:17 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int			i;
	long int	num;

	i = 0;
	num = n;
	if (num == 0)
		return ((int)i + 1);
	if (num < 0)
	{
		num = -num;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return ((int)i);
}

char	*ft_itoa(int n)
{
	char		*s;
	int			len;
	long int	num;

	num = n;
	len = ft_intlen(n) - 1;
	s = (char *)malloc(len + 2 * sizeof(char));
	if (!s)
		return (0);
	if (num < 0)
	{
		num = -num;
		s[0] = '-';
	}
	while (num > 9)
	{
		s[len--] = (num % 10) + '0';
		num /= 10;
	}
	s[len--] = num + '0';
	s[ft_intlen(n)] = '\0';
	return (s);
}
