/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:40:37 by souchane          #+#    #+#             */
/*   Updated: 2024/02/24 20:18:23 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
 #include <fcntl.h>
#include "gnlyes/get_next_line.h"

typedef struct s_game
{
	char **map;
	char *map_str;
	int	x_player;
	int	y_player;
	int	x_exit;
	int	y_exit;
} t_game;

// #define BUFFER_SIZE 1
