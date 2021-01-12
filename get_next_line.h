/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:26:33 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/12 17:57:45 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h> /* ===== DELETE ===== */
# include <unistd.h>
# define BUFFER_SIZE 32

typedef struct		s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
char				*ft_splitc(char **str);

#endif
