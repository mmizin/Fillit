/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:53:57 by ahonchar          #+#    #+#             */
/*   Updated: 2018/01/24 15:58:26 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_valid(char *str)
{
	int		i;
	int		hash;
	int		points;
	int		nl;

	i = -1;
	hash = 0;
	points = 0;
	nl = 4;
	while (str[++i])
	{
		(str[i] == '#') && hash++;
		(str[i] == '.') && points++;
		if (nl < 20)
		{
			if (str[nl] == '\n')
				nl = nl + 5;
			else
				return (0);
		}
	}
	if (hash != 4 || points != 12)
		return (0);
	else
		return (1);
}

static int		ft_check_arr(int arr[][2])
{
	int		i;
	int		j;
	int		res;

	i = 0;
	res = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if ((arr[i][0] == arr[j][0]) &&
			((arr[i][1] - arr[j][1]) == 1 || (arr[i][1] - arr[j][1]) == -1))
				res++;
			if ((arr[i][1] == arr[j][1]) &&
			((arr[i][0] - arr[j][0]) == 1 || (arr[i][0] - arr[j][0]) == -1))
				res++;
			j++;
		}
		i++;
	}
	return ((res >= 3 && res <= 4) ? 1 : 0);
}

static int		ft_tetr2(char array[][5])
{
	int	i;
	int	j;
	int	k;
	int	coord[4][2];

	i = 0;
	k = 0;
	while (array[i][0])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '#')
			{
				coord[k][0] = i;
				coord[k++][1] = j;
			}
			j++;
		}
		i++;
	}
	return (ft_check_arr(coord));
}

static int		ft_valid_figure(char *str)
{
	unsigned	i;
	unsigned	j;
	unsigned	k;
	char		tetr[5][5];

	i = 0;
	j = 0;
	while (str[i])
	{
		k = 0;
		while (str[i] != '\n')
			tetr[j][k++] = str[i++];
		i++;
		tetr[j][k] = '\0';
		j++;
	}
	tetr[j][0] = '\0';
	return (ft_tetr2(tetr));
}

int				check_file(char *str)
{
	unsigned	i;
	unsigned	j;
	char		block[21];

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 20)
			block[j++] = str[i++];
		block[j] = '\0';
		if (!ft_valid(block))
			return (0);
		if (!ft_valid_figure(block))
			return (0);
		if (str[i])
		{
			if (str[i] == '\n' && str[i + 1])
				i++;
			else
				return (0);
		}
	}
	return (i == 0 ? 0 : 1);
}
