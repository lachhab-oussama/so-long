/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckecker_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:49:19 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/02 11:58:24 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_num_of_elements(t_big *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[i])
		{
			if (line[i] == 'C')
				data->collectibles_number += 1;
			if (line[i] == 'P')
				data->player_number += 1;
			if (line[i] == 'E')
				data->exit_number += 1;
			i++;
		}
		free(line);
		i = 0;
	}
}

void	chek_elements_of_map(t_big *data)
{
	int	fd;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
	{
		print_error("Error :\nopening map file field");
		return ;
	}
	put_num_of_elements(data, fd);
	close(fd);
	validation_of_map(data);
}

void	validation_of_map(t_big *data)
{
	if (data->player_number != 1 || data->exit_number != 1)
	{
		print_error("Error :\nmap non valid check player or exit number");
		exit(0);
	}
}
