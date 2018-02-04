/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:43:49 by ahonchar          #+#    #+#             */
/*   Updated: 2018/01/24 15:58:10 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	set_figure(char **out, int i, int j, t_list *list)
{
	int k;
	int a;
	int b;

	k = -1;
	while (++k < 4)
	{
		a = i + list->coord[k][0];
		b = j + list->coord[k][1];
		if (a < 0 || b < 0 || !out[a] || !out[a][b] || out[a][b] != '.')
			return (0);
	}
	k = -1;
	a = i + list->coord[0][0];
	b = j + list->coord[0][1];
	list->out_coord[0] = a;
	list->out_coord[1] = b;
	while (++k < 4)
	{
		a = i + list->coord[k][0];
		b = j + list->coord[k][1];
		out[a][b] = list->letter;
	}
	return (1);
}

static void	clear(t_list *list, char **out)
{
	int i;
	int j;

	i = 0;
	while (out[i])
	{
		j = 0;
		while (out[i][j])
		{
			if (out[i][j] == (list->letter))
				out[i][j] = '.';
			j++;
		}
		i++;
	}
	list->out_coord[0] = 0;
	list->out_coord[1] = 0;
}

static int	replace_previus(char **out, t_list *list, int size)
{
	int i;
	int j;

	i = list->out_coord[0];
	j = list->out_coord[1];
	j++;
	clear(list, out);
	while (i < size)
	{
		while (j < size)
		{
			if (set_figure(out, i, j, list))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static int	set_on_map(t_list *list, char **out)
{
	int i;
	int j;

	i = 0;
	while (out[i])
	{
		j = 0;
		while (out[i][j])
		{
			if (out[i][j] == '.')
				if (set_figure(out, i, j, list))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			print_map(char **out, t_list *list, int size)
{
	while (list)
	{
		if (set_on_map(list, out))
		{
			list = list->next;
			if (!list)
				return (1);
			continue;
		}
		else
		{
			while (list->prev && !replace_previus(out, list->prev, size))
				list = list->prev;
			if (!list->prev)
				return (0);
		}
	}
	return (0);
}
