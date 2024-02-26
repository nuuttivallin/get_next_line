/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:59:56 by nvallin           #+#    #+#             */
/*   Updated: 2023/12/13 18:34:25 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd[6553];
	int		i;
	char	*string;

	i = 0;
	fd[0] = open(argv[1], O_RDWR);
	fd[1] = open(argv[2], O_RDWR);
	fd[2] = 0;
	while (i < argc - 1)
	{
		string = get_next_line(fd[0]);
		printf("%s", string);
		free(string);
		string = get_next_line(fd[1]);
		printf("%s", string);
		free(string);
		string = get_next_line(fd[2]);
		printf("%s", string);
		free(string);
		i++;
	}
	return (0);
}
