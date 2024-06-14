/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:49:51 by rpires-c          #+#    #+#             */
/*   Updated: 2024/06/14 14:55:33 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	a;

	if (str == NULL)
		return (0);
	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	cont;
	char	*str;

	cont = 0;
	str = (char *)s;
	{
		while (cont < n)
		{
			str[cont] = '\0';
			cont++;
		}
	}
}

int	count_char(char *str)
{
	int	a;

	a = 0;
	if (str == NULL)
	{
		return (0);
	}
	while (str[a] != '\0')
	{
		if (str[a] == '\n')
			return (1);
		a++;
	}
	return (0);
}

char	*concatenate_str(char *checkpoint, char *tmp)
{
	int		len;
	int		i;
	char	*ret;
	int		len_checkpoint;

	len_checkpoint = ft_strlen(checkpoint);
	i = -1;
	len = len_checkpoint + ft_strlen(tmp) + 1;
	ret = (char *)malloc(len * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, len);
	if (checkpoint != NULL)
	{
		while (checkpoint[++i] != '\0')
			ret[i] = checkpoint[i];
		free(checkpoint);
	}
	i = -1;
	while (tmp[++i] != '\0')
		ret[len_checkpoint + i] = tmp[i];
	ret[len_checkpoint + i] = '\0';
	return (ret);
}

char	*copy(char *str, int a, int frees)
{
	char	*ret;
	int		i;

	i = -1;
	ret = (char *)malloc(a + 1 * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, a + 1);
	while (++i < a)
		ret[i] = str[i];
	ret[i] = '\0';
	if (frees == 1)
		free(str);
	return (ret);
}