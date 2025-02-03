/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:24:29 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/02 16:07:35 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_extention_map(t_big *data)
{
	int	i;

	i = 0;
	while (data->map_path[i])
	{
		i++;
	}
	if (ft_strcmp(data->map_path + i - 4, ".ber") == 0)
	{
		print_error("Error : \nYour Extention file map not .ber\n");
		exit(0);
	}
}
