/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:36:04 by eramusho          #+#    #+#             */
/*   Updated: 2022/12/25 10:32:50 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (count);
}

static int	*start_index(char const *s, char c)
{
	int	*delimiter;
	int	i;
	int	j;
	int	word;

	i = -1;
	j = 0;
	word = 0;
	delimiter = (int *)malloc(sizeof(int) * count_words(s, c));
	if (!delimiter)
	{
		free(delimiter);
		return (0);
	}
	while (s[++i])
	{
		if (s[i] != c && word == 0)
		{
			word = 1;
			delimiter[j++] = i;
		}
		else if (s[i] == c)
			word = 0;
	}
	return (delimiter);
}

static int	len_word(char const *s, char c, int start)
{
	int	len;
	int	i;

	len = 0;
	i = start;
	while (s[i] != c && s[i] != '\0')
	{	
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		*start;

	i = 0;
	if (!s)
		return (0);
	start = start_index(s, c);
	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
	{
		free(array);
		return (0);
	}
	while (i < count_words(s, c))
	{
		array[i] = ft_substr(s, start[i], len_word(s, c, start[i]));
		i++;
	}
	array[i] = NULL;
	free(start);
	return (array);
}
