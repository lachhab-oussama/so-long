/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:48:21 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/02 11:09:02 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_tab_and_map(t_big *data)
{
	int	i;

	if (data->map)
	{
		i = 0;
		while (data->map[i])
			free(data->map[i++]);
		free(data->map);
	}
	if (data->tab)
	{
		i = 0;
		while (data->tab[i])
			free(data->tab[i++]);
		free(data->tab);
	}
}

void	cleanup(t_big *data)
{
	free_tab_and_map(data);
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_player)
		mlx_destroy_image(data->mlx, data->img_player);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
	if (data->img_collect)
		mlx_destroy_image(data->mlx, data->img_collect);
	if (data->img_trace_player)
		mlx_destroy_image(data->mlx, data->img_trace_player);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
