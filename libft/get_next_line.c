/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:05:08 by sdatskov          #+#    #+#             */
/*   Updated: 2019/03/08 12:05:10 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list			*check_lst(t_list **mainlst, int fd)
{
	t_list	*tmplst;

	tmplst = *mainlst;
	while (tmplst)
	{
		if ((int)tmplst->content_size != fd)
			tmplst = tmplst->next;
		else
			return (tmplst);
	}
	tmplst = ft_lstnew(0, 0);
	tmplst->content_size = (size_t)fd;
	if (tmplst->content == NULL)
		tmplst->content = (void *)ft_strdup("");
	tmplst->next = *mainlst;
	*mainlst = tmplst;
	return (tmplst);
}

static	void			read_str(t_list *strread)
{
	int		i;
	char	*leak;
	char	strbuf[BUFF_SIZE + 1];

	if ((!strread->content) || (!ft_strchr(strread->content, '\n')))
	{
		while ((i = read((int)strread->content_size, strbuf, BUFF_SIZE)))
		{
			strbuf[i] = '\0';
			leak = strread->content;
			strread->content = ft_strjoin(strread->content, strbuf);
			free(leak);
			if (ft_strchr(strbuf, '\n') != 0)
				break ;
		}
	}
}

static	char			*gnl_rewrite(t_list *fd_head)
{
	char	*buff;
	char	*str;

	str = fd_head->content;
	buff = str;
	while (*buff && (*buff != '\n'))
		buff++;
	if (*buff == '\n' || *buff == '\r')
		buff++;
	buff = ft_strdup(buff);
	free(str);
	return (buff);
}

static	char			*ft_copy(char *str)
{
	char	*buff;
	char	*smth;

	buff = str;
	if ((*str) == (char)NULL)
		return (str);
	while (*buff != (char)NULL && *buff != '\n')
		buff++;
	smth = ft_strsub(str, 0, (buff - str));
	return (smth);
}

int						get_next_line(const int fd, char **line)
{
	static t_list	*mainlst = NULL;
	t_list			*tmplst;
	char			buffer[BUFF_SIZE + 1];

	if ((fd < 0) || (!line) || ((int)read(fd, buffer, 0) < 0)
		|| (BUFF_SIZE < 1))
		return (-1);
	tmplst = check_lst(&mainlst, fd);
	read_str(tmplst);
	*line = ft_copy(tmplst->content);
	if (ft_strlen(*line) == 0 && ft_strlen(tmplst->content) == 0)
		return (0);
	tmplst->content = gnl_rewrite(tmplst);
	return (1);
}
