/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:20:14 by tshata            #+#    #+#             */
/*   Updated: 2018/06/14 14:57:47 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_iswhitespace(int s)
{
	return (s == ' ' || s == '\t' || s == '\n');
}

char		*ft_strtrim(const char *s)
{
	size_t			i;
	size_t			len;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_iswhitespace(s[i]))
		i++;
	len = ft_strlen((char *)s) - 1;
	while (len > i && ft_iswhitespace(s[len]))
		len--;
	if (len < i)
		return (str = ft_strdup(""));
	return (str = ft_strsub(s, i, len - i + 1));
}
