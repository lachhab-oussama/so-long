/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:11:54 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/02 16:22:18 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char *av[])
{
	t_big	data;

	if (argumet_num(ac))
	{
		data.map_path = av[1];
		check_extention_map(&data);
		init_data(&data);
		get_map_size(&data);
		load_map(&data);
		check_all_lines(&data);
		chek_elements_of_map(&data);
		flood_fill(&data);
		data.mlx = mlx_init();
		if (!data.mlx)
			return (1);
		data.win = mlx_new_window(data.mlx, data.map_width * WIDTH_PIXEL,
				data.map_height * HEIGHT_PIXEL, "So_long");
		if (!initialize_images(&data))
			return (1);
		prepare_maps(&data);
		mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
		mlx_hook(data.win, 17, 0, close_window, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
