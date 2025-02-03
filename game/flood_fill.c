/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:53:16 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/02 15:16:20 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	fill(char **tab, t_big *data, int begin_y, int begin_x)
{
	int	map_height;
	int	map_width;

	map_height = data->map_height;
	map_width = data->map_width;
	if (begin_y < 0 || begin_x < 0 || begin_y >= map_height
		|| begin_x >= map_width)
	{
		return ;
	}
	if (tab[begin_y][begin_x] == '1' || tab[begin_y][begin_x] == 'F')
		return ;
	tab[begin_y][begin_x] = 'F';
	fill(tab, data, begin_y + 1, begin_x);
	fill(tab, data, begin_y - 1, begin_x);
	fill(tab, data, begin_y, begin_x + 1);
	fill(tab, data, begin_y, begin_x - 1);
}

void	flood_fill(t_big *data)
{
	int	i;
	int	j;

	get_map_in_tab(data);
	map_border_check(data);
	fill(data->tab, data, data->y, data->x);
	i = 0;
	while (data->tab[i])
	{
		j = 0;
		while (data->tab[i][j])
		{
			if (data->tab[i][j] == 'C' || data->tab[i][j] == 'E')
			{
				print_error("Error :\nYour map not accessible to all elements\n");
				cleanup(data);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
