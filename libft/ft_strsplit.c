/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:42:09 by tshata            #+#    #+#             */
/*   Updated: 2018/06/07 14:25:34 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_word_count(char const *str, char c)
{
	int		i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			while (str[i] && str[i] != c)
				i++;
			wordcount++;
		}
	}
	return (wordcount);
}

char		**ft_strsplit(char const *s, const char c)
{
	char	**str;
	int		i;
	int		start;
	int	size;

	if (!s || !(str = (char **)malloc(sizeof(char *) *
					(ft_word_count(s, c) + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			str[size++] = ft_strsub(s, start, i - start);
		}
	}
	str[size] = NULL;
	return (str);
}
