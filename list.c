/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:59:41 by ahonchar          #+#    #+#             */
/*   Updated: 2018/01/24 15:57:04 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_list		*create_list(int size)
{
	t_list	*list;
	t_list	*begin;

	list = (t_list *)malloc(sizeof(t_list));
	list->prev = NULL;
	begin = list;
	while (--size)
	{
		list->next = (t_list *)malloc(sizeof(t_list));
		list->next->prev = list;
		list = list->next;
	}
	list->next = NULL;
	return (begin);
}

static	t_list		*copy_tetr(char *str)
{
	t_list		*tetr;
	t_list		*begin;
	int			i;
	int			j;
	int			k;

	tetr = create_list(count_tetr(str));
	begin = tetr;
	i = -1;
	j = 0;
	while (str[++i] && i < 546)
	{
		k = 0;
		while (k < 4)
			tetr->figure[j][k++] = str[i++];
		tetr->figure[j++][k] = '\0';
		if (j == 4 && i++)
		{
			tetr->figure[j][0] = '\0';
			tetr = tetr->next;
			j = 0;
		}
	}
	return (begin);
}

static	void		convert_coord(t_list *list)
{
	int i;
	int j;
	int buf[2];

	i = 0;
	j = 0;
	buf[0] = list->coord[0][0];
	buf[1] = list->coord[0][1];
	while (i < 4)
	{
		j = 0;
		list->coord[i][j] = list->coord[i][j] - buf[0];
		j++;
		list->coord[i][j] = list->coord[i][j] - buf[1];
		i++;
	}
}

static	void		get_coord(t_list *list)
{
	int			i;
	int			j;
	int			y;

	y = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (list->figure[i][j] == '#')
			{
				list->coord[y][0] = i;
				list->coord[y][1] = j;
				y++;
				list->figure[i][j] = list->letter;
			}
			j++;
		}
		i++;
	}
	convert_coord(list);
}

t_list				*copy_to_list(char *str)
{
	t_list		*begin;
	t_list		*list;
	char		letter;

	list = copy_tetr(str);
	begin = list;
	letter = 'A';
	while (list)
	{
		list->letter = letter++;
		list->out_coord[0] = 0;
		list->out_coord[1] = 0;
		get_coord(list);
		list = list->next;
	}
	return (begin);
}
