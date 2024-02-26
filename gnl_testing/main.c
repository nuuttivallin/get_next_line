/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:41:28 by nvallin           #+#    #+#             */
/*   Updated: 2023/12/12 15:51:07 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	main(int argc, char **argv)
{
	char	*file;
	int		fd[6553];
	char	*string;
	int		i = 1;
	int		n;
	int		last;

	file = "hello";
	fd[0] = open(file, O_RDWR);
	string = get_next_line(fd[0]);
	printf("%s", string);
	free(string);
	while (string != NULL)
	{
		string = get_next_line(fd[0]);
		printf("%s", string);
		free(string);
	}
	printf("%c", '\n');
	free(string);
	close(fd[0]);
	if (argc > 1)
	{
		while (i < argc)
		{
			n = i -1;
			while (n > 0 && ft_strncmp(argv[i], argv[n], 10) != 0)
				n--;
			if (ft_strncmp(argv[i], argv[n], 10) != 0)
			{
				fd[n] = open(argv[i], O_RDWR);
				last = n;
			}
			string = get_next_line(fd[last]);
			printf("%s", string);
			free(string);
			i++;
		}
	}
	return (0);
}
