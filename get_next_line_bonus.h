/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:26:33 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/04 16:40:51 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
t_list				*ft_lstadd_front(t_list **lst, int fd);
char				*ft_splitc(char **str);
char				*ft_strchr(const char *str, int chr);
int					ft_free_elm(t_list **list, t_list *elm);

#endif
