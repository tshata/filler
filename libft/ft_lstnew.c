/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:11:39 by tshata            #+#    #+#             */
/*   Updated: 2018/06/23 13:02:11 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlink;

	newlink = (t_list *)malloc(sizeof(t_list));
	if (!newlink)
		return (NULL);
	newlink->next = NULL;
	if (content != NULL)
	{
		newlink->content = (size_t *)malloc(content_size);
		if ((newlink->content) == NULL)
			return (NULL);
		ft_memcpy(newlink->content, content, content_size);
		newlink->content_size = content_size;
	}
	else
	{
		newlink->content = NULL;
		newlink->content_size = 0;
	}
	return (newlink);
}
