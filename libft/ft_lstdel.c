/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:09:34 by tshata            #+#    #+#             */
/*   Updated: 2018/06/23 12:26:21 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, int))
{
	if (!(*alst))
		return ;
	if ((*alst)->next != NULL)
	{
		ft_lstdel(&(*alst)->next, del);
	}
	if (*alst)
		ft_lstdelone(&(*alst), del);
}
