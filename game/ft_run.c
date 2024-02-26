/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:48:30 by souchane          #+#    #+#             */
/*   Updated: 2024/02/26 18:49:35 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void run(char *str)
{
	t_game game;

	game.map_str = str;
	game.map = ft_split(str, '\n');
	checkmap(game.map);
	check(&game);

	
	// int i = 0;
// 	while (game.map[i])
// 	{
// 		printf("%s\n", game.map[i]);
// 		i++;
// 	}
}