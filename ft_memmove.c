/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:15:42 by eramusho          #+#    #+#             */
/*   Updated: 2023/03/14 19:40:09 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;

	pdst = (char *)dst;
	psrc = (char *)src;
	if (dst == src)
		return (dst);
	if (src < dst)
	{
		while (len--)
			pdst[len] = psrc[len];
	}
	else
		while (len--)
			*pdst++ = *psrc++;
	return (dst);
}
