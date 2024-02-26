/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:28:31 by souchane          #+#    #+#             */
/*   Updated: 2024/02/26 18:52:20 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



char* readFromFileDescriptor(int fd) {
    char* content;
	char* str;

	content = NULL;
    while (1) {
        str = get_next_line(fd);
		if(str == NULL)
			break;
		if(ft_strlen(str) <= 2)
		{
			printf("Error\nWrong map\n");
			exit(1);
		}
		content = ft_strjoin(content, str);
		free(str);
    }
	if(content[ft_strlen(content) - 1] != '1')
	{
		printf("Error\nWrong map\n");
		exit(1);
	}
    return content;
}


int main(int ac, char **av)
{
	int fd;
	char	*str;
	if(ac == 2)
	{
		fd = ft_check_file(av[1]);
		str = readFromFileDescriptor(fd);
		run(str);
		// while(1);
	}
	else
		printf("error\n");
}