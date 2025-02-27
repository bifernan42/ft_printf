/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:02:08 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/05 18:29:05 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_manager1(const char *str, \
int *char_nb, t_directives s_dir, char *filler)
{
	if ((int)ft_strlen(str) > s_dir.precision)
		s_dir.field_width -= s_dir.precision;
	else
		s_dir.field_width -= (int)ft_strlen(str);
	if (!str && s_dir.precision >= 6)
		ft_putstr("(null)", char_nb);
	while (str && s_dir.precision > 0 && *str != '\0')
	{
		ft_putchar(*str, char_nb);
		str++;
		s_dir.precision--;
	}
	while (s_dir.field_width > 0)
	{
		ft_putchar(*filler, char_nb);
		s_dir.field_width--;
	}
}

static void	ft_manager2(const char *str, \
int *char_nb, t_directives s_dir, char *filler)
{
	s_dir.field_width -= s_dir.precision;
	while (s_dir.field_width > 0)
	{
		ft_putchar(*filler, char_nb);
		s_dir.field_width--;
	}
	if (!str && s_dir.precision >= 6)
		ft_putstr("(null)", char_nb);
	while (str && s_dir.precision > 0 && *str != '\0')
	{
		ft_putchar(*str, char_nb);
		str++;
		s_dir.precision--;
	}
}

void	ft_putstr2(const char *str, int *char_count, t_directives s_dir)
{
	char	filler;
	size_t	len;

	filler = ' ';
	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	if (s_dir.dot != '.')
		s_dir.precision = len;
	if (ft_is_minusf(s_dir.flags))
		ft_manager1(str, char_count, s_dir, &filler);
	else
		ft_manager2(str, char_count, s_dir, &filler);
}
