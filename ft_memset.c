/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:15:45 by eramusho          #+#    #+#             */
/*   Updated: 2023/02/22 14:28:28 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pb;

	pb = b;
	while (len > 0)
	{
		*pb = c;
		len--;
		pb++;
	}
	return (b);
}
 