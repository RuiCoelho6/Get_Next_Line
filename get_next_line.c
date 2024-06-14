/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:49:57 by rpires-c          #+#    #+#             */
/*   Updated: 2024/06/14 15:27:16 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*memory_eraser(char *array1, char *array2)
{
	free(array1);
	free(array2);
	return (NULL);
}

static void	*update_checkpoint(char *checkpoint, int fd)
{
	int		r;
	char	*tmp;

	tmp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (count_char(checkpoint) <= 0)
	{
		ft_bzero(tmp, BUFFER_SIZE + 1);
		r = read(fd, tmp, BUFFER_SIZE);
		if (r != 0)
		{
			checkpoint = concatenate_str(checkpoint, tmp);
			if (checkpoint == NULL)
				free(tmp);
		}
		if (ft_strlen(tmp) == 0 && ft_strlen(checkpoint) == 0)
			return (memory_eraser(tmp, checkpoint));
		ft_bzero(tmp, ft_strlen(tmp) + 1);
		if (r != BUFFER_SIZE)
			break;
	}
	if (tmp)
		free(tmp);
	return (checkpoint);
}

static char	*get_next_lines(int fd)
{
	char		*checkpoint;
	static char	*rest = NULL;
	int			len_checkpoint;
	int			i;

	i = 0;
	len_checkpoint = 0;
	checkpoint = rest;
	checkpoint = update_checkpoint(checkpoint, fd);
	if (checkpoint == NULL)
		return (NULL);
	if (len_checkpoint == 0)
		len_checkpoint = ft_strlen(checkpoint);
	while (checkpoint[i] != '\n' && len_checkpoint > i)
		i++;
	if (i == 0 && checkpoint[i] != '\n')
		return (memory_eraser(rest, checkpoint));
	rest = copy(&checkpoint[i + 1], len_checkpoint - i, 0);
	if (rest == NULL)
	{
		free(checkpoint);
		return (NULL);
	}
	return (copy(checkpoint, i + 1, 1));
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (get_next_lines(fd));
}


//  int main(void)
// {
// 	int id_arqi = open("teste.text", O_RDONLY);
// 	char *ok;
// 	ok =  get_next_line(id_arqi);
// 	//printf("%s",ok);
// 	//free(ok);
// 	// ok =  get_next_line(id_arqi);
// 	// //printf("%s",ok);
// 	// free(ok);
// 	//ok =  get_next_line(id_arqi);
// 	//ok =  get_next_line(id_arqi);
// 	//  printf("%s",ok);
// 	//  ok =  get_next_line(id_arqi);
// 	//  printf("%s",ok);
// 	//printf("%s",ok);
// 	 while(ok !=NULL)
// 	 {	printf("-%s",ok);
// 		free (ok);
// 	 	ok = get_next_line(id_arqi);
// 	 }
//  }