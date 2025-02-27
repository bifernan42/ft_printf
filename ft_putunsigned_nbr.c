/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:07:24 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/05 18:41:48 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_len_calculator2(char *rez, t_directives *s_dir)
{
	int	nbrlen;
	int	digits;

	digits = ft_strlen(rez);
	if (s_dir->precision > digits && s_dir->dot == '.')
		s_dir->zeroes = s_dir->precision - digits;
	nbrlen = s_dir->zeroes + digits;
	if (s_dir->field_width > nbrlen)
		s_dir->field_width -= nbrlen;
	else
		s_dir->field_width = 0;
}

static void	ft_draw_number2(char *rez, int *char_count, t_directives s_dir)
{		
	if (s_dir.field_width && *rez == '0' && s_dir.is_dot)
	{
		ft_putchar(' ', char_count);
		return ;
	}
	while (s_dir.zeroes > 0 && s_dir.dot == '.')
	{
		ft_putchar('0', char_count);
		s_dir.zeroes--;
	}
	if (s_dir.is_dot && !s_dir.precision && *rez == '0')
	{
		if (ft_is_zerof(s_dir.flags))
			ft_putchar(' ', char_count);
		return ;
	}
	while (*rez != '\0')
	{
		ft_putchar(*rez, char_count);
		rez++;
	}
}

static void	ft_manager(unsigned int nbr, \
char **rez, t_directives *s_dir, char *filler)
{
	*filler = ' ';
	*rez = ft_itoa(nbr);
	ft_len_calculator2(*rez, s_dir);
}

void	ft_putunsigned_nbr(unsigned int nbr, int *char_nb, t_directives s_dir)
{
	char	*rez;
	char	filler;

	ft_manager(nbr, &rez, &s_dir, &filler);
	if (ft_is_minusf(s_dir.flags))
	{
		ft_draw_number2(rez, char_nb, s_dir);
		while (s_dir.field_width > 0)
		{
			ft_putchar(filler, char_nb);
			s_dir.field_width--;
		}
	}
	else
	{
		if (ft_is_zerof(s_dir.flags) && s_dir.dot != '.')
			filler = '0';
		while (s_dir.field_width > 0)
		{
			ft_putchar(filler, char_nb);
			s_dir.field_width--;
		}
		ft_draw_number2(rez, char_nb, s_dir);
	}
	free(rez);
}
