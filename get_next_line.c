/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:06:11 by tshata            #+#    #+#             */
/*   Updated: 2018/07/30 13:42:51 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_lines(int fd, char **line, char **str)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		temp = ft_strdup(&str[fd][i + 1]);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str[1];
	int				ret;
	char			*temp;
	char			buffer[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		temp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (get_lines(fd, line, str));
}
