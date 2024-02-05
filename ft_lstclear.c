/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:21:57 by eramusho          #+#    #+#             */
/*   Updated: 2022/12/22 11:04:15 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*free_node;

	if (!del)
		return ;
	while (*lst != NULL)
	{
		del((*lst)->content);
		free_node = *lst;
		*lst = free_node->next;
		free(free_node);
	}
	*lst = NULL;
}
