/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:34:48 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/12 18:55:49 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstadd_front(t_list **lst, int fd)
{
	t_list	*new;

	if ((new = malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->fd = fd;
	if ((new->content = malloc(sizeof(*(new->content)))) == NULL)
		return (NULL);
	new->next = *lst;
	*lst = new;
	return (*lst);
}

t_list	*ft_get_fd_in_list(t_list *lst, int fd)
{
	while (lst != NULL)
		if (lst->fd == fd)
			return (lst);
		else
			lst = lst->next;
	return (NULL);
}

char	*ft_strchr(const char *str, int chr)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)chr)
			return ((char*)&str[i]);
		i++;
	}
	if ((unsigned char)chr == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdupcat(char *dest, char *src)
{
	char			*res;
	unsigned long	i;
	unsigned long	dest_start;
	unsigned long	src_size;

	i = 0;
	dest_start = 0;
	while (dest[i++])
		dest_start++;
	i = 0;
	src_size = 0;
	while (src[i++])
		src_size++;
	i = -1;
	if (!(res = malloc(sizeof(*res) * (dest_start + src_size + 1))))
		return (NULL);
	while (dest[++i])
		res[i] = dest[i];
	i = -1;
	while (src[++i])
		res[dest_start + i] = src[i];
	res[dest_start + i] = '\0';
	free(dest);
	return (res);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*line_list;
	int				ret;
	int				result;
	char			buffer[BUFFER_SIZE + 1];
	t_list			*elm;

	if (fd < 0 || line == NULL) // A protéger
		return (-1);
	if ((elm = ft_get_fd_in_list(line_list, fd)) == NULL)
		if ((elm = ft_lstadd_front(&line_list, fd)) == NULL)
			return (-1);
	result = 1;
	while (ft_strchr(elm->content, '\n') == NULL)
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)))
			buffer[ret] = '\0';
		else
		{
			result = 0;
			break ;
		}
		elm->content = ft_strdupcat(elm->content, buffer);
	}
	if ((*line = ft_splitc(&elm->content)) == NULL)
		return (-1);
	return (result);
}
