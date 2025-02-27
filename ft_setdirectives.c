/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setdirectives.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:37:17 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/02 14:43:22 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_setinteger(int *integer, char *digitstring)
{
	if (*digitstring != '@')
		*integer = ft_atoi(digitstring);
	else
		*integer = 0;
}

void	ft_setdirectives(t_directives *s_dir)
{
	char	**tab;
	int		field_width;
	int		precision;
	int		i;

	tab = ft_split(s_dir->raw_dir, '|');
	free(s_dir->raw_dir);
	s_dir->raw_dir = NULL;
	ft_setinteger(&field_width, tab[1]);
	ft_setinteger(&precision, tab[3]);
	s_dir->flags = tab[0];
	s_dir->field_width = field_width;
	s_dir->dot = tab[2][0];
	s_dir->precision = precision;
	s_dir->specifier = tab[4][0];
	i = 1;
	while (i < 5)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
