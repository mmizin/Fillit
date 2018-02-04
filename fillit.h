/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:03:02 by ahonchar          #+#    #+#             */
/*   Updated: 2018/01/12 17:03:42 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

int					check_file(char *str);
int					map_size(char *str);
int					count_tetr(char *str);

typedef struct		s_list
{
	char			figure[5][5];
	char			letter;
	int				out_coord[2];
	int				coord[4][2];
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

t_list				*copy_to_list(char *str);
int					print_map(char **out, t_list *list, int size);

#endif
