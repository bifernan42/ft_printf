/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:16:06 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/04 20:29:33 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_len_calculator(char *hexnum, t_directives *s_dir)
{
	int	nbrlen;
	int	digits;

	digits = ft_strlen(hexnum);
	if (s_dir->precision > digits && s_dir->dot == '.')
		s_dir->zeroes = s_dir->precision - digits;
	nbrlen = s_dir->zeroes + digits;
	if (s_dir->field_width > nbrlen)
		s_dir->field_width -= nbrlen;
	else
		s_dir->field_width = 0;
}

static void	ft_putprefix(int first_char, \
		int id, int *char_count, t_directives *s_dir)
{
	if (id == 2)
	{
		ft_putstr("0x", char_count);
		if (ft_is_minusf(s_dir->flags))
			s_dir->field_width -= 2;
	}
	if (id == 0 && ft_is_hashtagf(s_dir->flags) && first_char)
	{
		ft_putstr("0x", char_count);
		if (ft_is_minusf(s_dir->flags))
			s_dir->field_width -= 2;
	}
	if (id == 1 && ft_is_hashtagf(s_dir->flags) && first_char)
	{
		ft_putstr("0X", char_count);
		if (ft_is_minusf(s_dir->flags))
			s_dir->field_width -= 2;
	}
}

static void	ft_putfiller(char filler, int field_width, int *char_count)
{
	while (field_width > 0)
	{
		ft_putchar(filler, char_count);
		field_width--;
	}
}

static void	ft_manager(t_directives s_dir, \
char first_char, int *char_count, int id)
{
	char	filler;

	filler = ' ';
	if (ft_is_zerof(s_dir.flags) && first_char != -8 && !s_dir.is_dot)
		filler = '0';
	if (((ft_is_hashtagf(s_dir.flags) && (id == 0 || id == 1)) \
	|| id == 2) && first_char)
		s_dir.field_width -= 2;
	ft_putfiller(filler, s_dir.field_width, char_count);
	ft_putprefix(first_char, id, char_count, &s_dir);
	ft_putfiller('0', s_dir.zeroes, char_count);
}	

void	ft_puthex(long number, int id, int *char_count, t_directives s_dir)
{
	int			first_char;
	t_values	s_val;
	char		*hexnum;
	char		filler;

	filler = ' ';
	s_val = ft_convertbase(number, &id);
	hexnum = s_val.to_print;
	first_char = (int)(hexnum[0] - '0');
	if (!hexnum)
		return ;
	ft_len_calculator(hexnum, &s_dir);
	if (ft_is_minusf(s_dir.flags))
	{
		ft_putprefix(first_char, id, char_count, &s_dir);
		ft_putfiller('0', s_dir.zeroes, char_count);
		ft_miniputhex(hexnum, &s_dir, char_count);
		ft_putfiller(filler, s_dir.field_width, char_count);
	}
	else
	{
		ft_manager(s_dir, first_char, char_count, id);
		ft_miniputhex(hexnum, &s_dir, char_count);
	}
	free(s_val.result);
}
