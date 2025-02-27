/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:15:15 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/02 19:55:31 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(long n)
{	
	int	count;

	count = 0;
	if (n >= -9 && n <= 9)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_caf(long *rez, int *i)
{
	char	*number;

	number = (char *)malloc(sizeof(char) * (ft_count(*rez) + 1));
	*i = ft_count(*rez);
	return (number);
}

char	*ft_itoa(long n)
{
	long	rez;
	char	*number;
	int		i;

	rez = n;
	if (rez < 0)
		rez *= -1;
	number = ft_caf(&rez, &i);
	if (!number)
		return (NULL);
	number[i] = '\0';
	if (rez == 0)
	{
		i--;
		number[i] = '0';
	}
	while (rez != 0)
	{
		i--;
		number[i] = (rez % 10 + '0');
		rez /= 10;
	}
	return (number);
}
