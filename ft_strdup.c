/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:15:51 by eramusho          #+#    #+#             */
/*   Updated: 2022/12/25 10:33:04 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dup)
		return (0);
	ft_memcpy(dup, s1, ft_strlen(s1));
	dup[ft_strlen(s1)] = '\0';
	return (dup);
}
