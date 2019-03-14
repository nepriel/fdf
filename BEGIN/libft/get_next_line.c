/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlhomme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:48:40 by vlhomme           #+#    #+#             */
/*   Updated: 2019/03/13 22:22:49 by vlhomme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		lncop(char **line, char *content, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (content[i] && content[i] != c)
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	return (i);
}

t_list	*get_live(int fd, t_list **grosse)
{
	t_list	*tmp;

	if (!grosse)
		return (NULL);
	tmp = *grosse;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(grosse, tmp);
	return (tmp);
}

int		read_fd(const int fd, char **content)
{
	int		res;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	while ((res = read(fd, buff, BUFF_SIZE)))
	{
		buff[res] = '\0';
		tmp = *content;
		if (!(*content = ft_strjoin(*content, buff)))
			return (-1);
		free(tmp);
		if (ft_strchr(buff, ENDL))
			break ;
	}
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	size_t			res;
	static t_list	*grosse;
	t_list			*live;
	char			*tmp;

	if (fd < 0 || !line || (read(fd, buff, 0)) < 0 ||
			(!(live = get_live(fd, &grosse))))
		return (-1);
	tmp = live->content;
	res = read_fd(fd, &tmp);
	live->content = tmp;
	if (!res && !*tmp)
		return (0);
	res = lncop(line, live->content, ENDL);
	tmp = live->content;
	if (tmp[res] != '\0')
	{
		live->content = ft_strdup(&((live->content)[res + 1]));
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
}
