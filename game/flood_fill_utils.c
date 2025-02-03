/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:13:27 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/02 15:16:32 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player_position(t_big *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->tab[i])
	{
		j = 0;
		while (data->tab[i][j])
		{
			if (data->tab[i][j] == 'P')
			{
				data->x = j;
				data->y = i;
			}
			j++;
		}
		i++;
	}
}

static int	get_count_map_lines(int fd)
{
	int		line_count;
	char	*line;

	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		line_count++;
	}
	close(fd);
	return (line_count);
}

static int	get_allocate_map(t_big *data, int fd)
{
	int	line_count;

	line_count = get_count_map_lines(fd);
	if (line_count <= 0)
	{
		print_error("Error :\nError reading map or empty map");
		return (0);
	}
	data->tab = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!data->tab)
	{
		print_error("Error :\nMemory allocation failed");
		return (0);
	}
	data->tab[line_count] = NULL;
	return (1);
}

void	get_map_in_tab(t_big *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(data->map_path, O_RDONLY);
	if (!get_allocate_map(data, fd))
		return ;
	fd = open(data->map_path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->tab[i] = line;
		i++;
	}
	data->tab[i] = NULL;
	close(fd);
	get_player_position(data);
}
