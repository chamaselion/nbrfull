/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <szikorabalintw@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:52:34 by bszikora          #+#    #+#             */
/*   Updated: 2023/11/05 22:36:04 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_atoi(char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 0;
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	while (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			b = -b;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		a = a * 10 + (str[c] - '0');
		c++;
	}
	return (a * b);
}

void	kinda_printf(char *result)
{
	write(1, "In words: ", 10);
	write(1, result, ft_strlen(result));
	write(1, "\n", 1);
}
