/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:15:40 by eramusho          #+#    #+#             */
/*   Updated: 2022/12/22 10:39:03 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*pdst;
	const char	*psrc;

	pdst = dst;
	psrc = src;
	if (n == 0 || dst == src)
		return (dst);
	while (n > 0)
	{
		*pdst++ = *psrc++;
		n--;
	}
	return ((void *)dst);
}
