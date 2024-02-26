/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:28:31 by souchane          #+#    #+#             */
/*   Updated: 2024/02/24 20:39:29 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

char* readFromFileDescriptor(int fd) {
    char* content;
	char* str;

	content = NULL;
    while (1) {
        str = get_next_line(fd);
		if(str == NULL)
			break;
		if(strlen(str) <= 2)
		{
			printf("Error\nWrong map\n");
			exit(1);
		}
		content = ft_strjoin(content, str);
		free(str);
    }
	if(content[strlen(content) - 1] != '1')
	{
		printf("Error\nWrong map\n");
		exit(1);
	}
    return content;
}
int ft_check(char *f_str)
{
	int fd;
	unsigned long len;
	char *a;
	len = strlen((const char *)f_str);
	a = f_str + (len - 4);
	if (strcmp(a, ".ber") || strlen((const char *)f_str) <= 4)
	{
		printf("error");
		exit(1);
	}
	fd = open(f_str, O_RDONLY);
	if (fd == -1)
	{
		printf("error");
		exit(1);
	}
	return (fd);
}
void checkmap(char **tab)
{
	int 	len;
	size_t	firstline;
	size_t	i;
	int		j;
	len = 0;
	while(tab[len])
		len++;
	if(len <= 2)
	{
		printf("Error\nWrong map\n");
		exit(1);
	}
	firstline = strlen(tab[0]);
	i = 1;
	while (tab[i])
	{
		if (firstline != strlen(tab[i]))
		{
			printf("Error\nMap not rectangular!\n");
			exit(1);
		}
		i++;
	}
	j = 0; 
	while(firstline > j)
	{
		if (tab[0][j] != '1' ||  tab[len - 1][j] != '1')
		{
			printf("Error\nmap not surrounded by walls!\n");
			exit(1);
		}
		j++;
	}
	j = 0;
	while(len > j)
	{
		if (tab[j][0] != '1' ||  tab[j][firstline - 1] != '1')
		{
			printf("Error\nmap not surrounded by walls!\n");
			exit(1);
		}
		j++;
	}
}

void check_coll(t_game *game)
{
	int i;
	int len;
	int j;
	
	len = 0;
	i = 0;
	while(game->map[i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] != 'C')
				len++;
		}
		i++;
	}
	if (len == 0)
	{
		printf("Error\n no collection!\n");
		exit(1);
	}
}
void check_player(t_game *game)
{
	int i;
	int len;
	int j;
	
	len = 0;
	i = 0;
	while(game->map[i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] != 'P')
			{
				game->x_player = j;
				game->y_player = i;
				len++;
			}
		}
		i++;
	}
	if (len != 1)
	{
		printf("Error\nmap has wrong player!\n");
		exit(1);
	}
}
void check_exit(t_game *game)
{
	int i;
	int len;
	int j;
	
	len = 0;
	i = 0;
	while(game->map[i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] != 'E')
			{
				game->x_exit = j;
				game->y_exit = i;
				len++;
			}
		}
		i++;
	}
	if (len != 1)
	{
		printf("Error\nmap has wrong exit!\n");
		exit(1);
	}
}

void check_none_char(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	while(game->map[i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] != 'P' && game->map[i][j] != 'E' && game->map[i][j] != 'C'
				&& game->map[i][j] != '0' && game->map[i][j] != '1')
			{
				printf("Error\nmap has wrong characters!\n");
				exit(1);
			}
		}
		i++;
	}
}
void check_char(t_game *game)
{
	check_player(game);
	check_coll(game);
	check_exit(game);
	check_none_char(game);
}
void run(char *str)
{
	t_game game;

	game.map_str = str;
	game.map = ft_split(str, '\n');
	checkmap(game.map);
	check_char(&game);
	// int i = 0;
// 	while (game.map[i])
// 	{
// 		printf("%s\n", game.map[i]);
// 		i++;
// 	}
}
int main(int ac, char **av)
{
	int fd;
	char	*str;
	if(ac == 2)
	{
		fd = ft_check(av[1]);
		str = readFromFileDescriptor(fd);
		run(str);
		// while(1);
	}
	else
		printf("error\n");
}