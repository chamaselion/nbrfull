/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <szikorabalintw@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:11:13 by bszikora          #+#    #+#             */
/*   Updated: 2023/11/06 17:46:27 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	wordcitcut(char *nbr, int length, int numsegments);
int		ft_strlen(char *str);
int		check_error(char *nbr);
void	process_nbr(char *nbr);
int		handle_dict(void);

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	while (i < argc)
	{
		if (check_error(argv[i]))
			return (1);
		handle_dict();
		process_nbr(argv[i]);
		i++;
	}
	return (0);
}

int	check_error(char *nbr)
{
	int	j;

	j = 0;
	while (nbr[j] != '\0')
	{
		if (nbr[j] < '0' || nbr[j] > '9')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		j++;
	}
	return (0);
}

void	process_nbr(char *nbr)
{
	int	length;
	int	numsegments;

	length = ft_strlen(nbr);
	numsegments = (length + 2) / 3;
	wordcitcut(nbr, length, numsegments);
}