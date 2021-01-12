/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:05:34 by vfurmane          #+#    #+#             */
/*   Updated: 2021/01/12 18:50:25 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trimc(const char *str)
{
	int		i;
	int		str_len;
	char	*new_content;

	str_len = 0;
	while (str[str_len])
		str_len++;
	if ((new_content = malloc((str_len + 1) * sizeof(*new_content))) == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		new_content[i] = str[i];
	new_content[i] = '\0';
	return (new_content);
}

char	*ft_splitc(char **str)
{
	int		i;
	int		str_len;
	char	*new_str;
	char	*new_content;

	str_len = 0;
	while ((*str)[str_len] && (*str)[str_len] != '\n')
		str_len++;
	if ((new_str = malloc((str_len + 1) * sizeof(*new_str))) == NULL)
		return (NULL);
	i = -1;
	while (++i < str_len)
		new_str[i] = (*str)[i];
	new_str[i++] = '\0';
	new_content = &(*str)[i];
	if ((new_content = ft_trimc(new_content)) == NULL)
		return (NULL);
	free(*str);
	*str = new_content;
	return (new_str);
}
