/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:28:31 by souchane          #+#    #+#             */
/*   Updated: 2024/02/12 17:15:55 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int ft_check(char f_str)
{
	int fd;
	int len;
	char *a;
	len = strlen(f_str);
	a = f_str + (len - 4);
	if (strcmp(a, ".ber") || strlen(f_str <= 4))
	{
		printf("error");
		exit(1);
	}
	fd = open(f_str);
	if (fd == -1)
	{
		printf("error");
		exit(1);
	}
	return (fd);
}
int main(int ac, char **av)
{
	int fd;
	if(ac == 2)
	{
		fd = ft_check(av[1]);
	}
	else
	printf("error\n");
}