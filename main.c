/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:52:39 by ahonchar          #+#    #+#             */
/*   Updated: 2018/01/24 15:57:25 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"
#include <stdlib.h>

#define BUFF 545

char		**new_map(int size)
{
	char	**out;
	int		i;
	int		j;

	i = -1;
	out = (char **)malloc(sizeof(out) * size + 1);
	while (++i < size)
		out[i] = (char *)malloc(sizeof(out[i]) * size + 1);
	out[i] = NULL;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			out[i][j++] = '.';
		out[i][j] = '\0';
		i++;
	}
	return (out);
}

void		ft_putstr(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char		**find_solution(t_list *list, int size)
{
	char	**out;

	out = new_map(size);
	while (!print_map(out, list, size))
	{
		free(out);
		out = new_map(++size);
	}
	free(list);
	return (out);
}

int			open_read(char *str, int ac, char *av)
{
	int		fd;
	int		ret;
	char	c;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	ret = read(fd, str, BUFF);
	str[ret] = '\0';
	if (!check_file(str) || read(fd, &c, 1))
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	return (1);
}

int			main(int ac, char **av)
{
	char	str[BUFF + 1];
	char	**new;
	int		i;

	if (!open_read(str, ac, av[1]))
		return (0);
	new = find_solution(copy_to_list(str), map_size(str));
	i = 0;
	while (new[i])
	{
		ft_putstr(new[i++]);
		ft_putstr("\n");
	}
	free(new);
	new = NULL;
	return (0);
}
