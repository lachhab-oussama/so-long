/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:48:25 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/02 15:11:50 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	fill_map(t_big *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i == 0)
			data->map_width = (int)ft_strlen(line) - 1;
		free(line);
		i++;
	}
	data->map_height = i;
}

void	get_map_size(t_big *data)
{
	int	fd;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
	{
		print_error("Error :\nopening map file field");
		return ;
	}
	fill_map(data, fd);
	close(fd);
	if (data->map_width == data->map_height)
	{
		print_error("Error :\nmap not rectangular");
		exit(0);
	}
}
