/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:06:46 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/05 18:41:57 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_len_calculator(int nbr, char *rez, t_directives *s_dir)
{
	int	is_neg;
	int	nbrlen;
	int	digits;

	is_neg = 0;
	nbrlen = 0;
	digits = ft_strlen(rez);
	if (nbr < 0)
		is_neg = 1;
	if (nbr >= 0 && ft_is_plusf(s_dir->flags))
		s_dir->is_plus = 1;
	else if (nbr >= 0 && ft_is_spacef(s_dir->flags))
		s_dir->is_space = 1;
	if (s_dir->precision > digits && s_dir->dot == '.')
		s_dir->zeroes = s_dir->precision - digits;
	nbrlen = is_neg + s_dir->is_plus + s_dir->is_space + s_dir->zeroes + digits;
	if (s_dir->field_width > nbrlen)
		s_dir->field_width -= nbrlen;
	else
		s_dir->field_width = 0;
}

static void	ft_draw_number(int nbr, char *rez, \
int *char_count, t_directives s_dir)
{		
	if (nbr == 0 && s_dir.field_width && nbr == 0 && s_dir.is_dot)
	{
		ft_putchar(' ', char_count);
		return ;
	}
	if (s_dir.is_dot && !s_dir.precision && nbr == 0)
	{
		if (ft_is_zerof(s_dir.flags))
			ft_putchar(' ', char_count);
		return ;
	}
	if ((nbr < 0) && !s_dir.drawn_minus)
		ft_putchar('-', char_count);
	else if (nbr >= 0 && ft_is_plusf(s_dir.flags))
		ft_putchar('+', char_count);
	while (s_dir.zeroes > 0 && s_dir.dot == '.')
	{
		ft_putchar('0', char_count);
		s_dir.zeroes--;
	}
	ft_putstr(rez, char_count);
}

static void	ft_putfiller(char filler, int field_width, int *char_count)
{
	while (field_width > 0)
	{
		ft_putchar(filler, char_count);
		field_width--;
	}
}

static void	ft_manager(int is_space, int *char_count)
{		
	if (is_space)
		ft_putchar(' ', char_count);
}

void	ft_putnbr(int nbr, int *char_count, t_directives s_dir)
{
	char	*rez;

	rez = ft_itoa(nbr);
	ft_len_calculator(nbr, rez, &s_dir);
	if (ft_is_minusf(s_dir.flags))
	{
		ft_draw_number(nbr, rez, char_count, s_dir);
		ft_putfiller(s_dir.filler, s_dir.field_width, char_count);
	}
	else
	{
		if (ft_is_zerof(s_dir.flags) && s_dir.dot != '.')
		{
			s_dir.filler = '0';
			if (nbr < 0 && !s_dir.drawn_minus)
			{
				ft_putchar('-', char_count);
				s_dir.drawn_minus = 1;
			}
		}
		ft_manager(s_dir.is_space, char_count);
		ft_putfiller(s_dir.filler, s_dir.field_width, char_count);
		ft_draw_number(nbr, rez, char_count, s_dir);
	}
	free(rez);
}
