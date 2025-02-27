/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managerwhile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:02:10 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/15 16:15:56 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_managerwhile(const char ***format, t_directives *s_dir, \
const char *options)
{
	while (ft_isflag(***format, options) && ***format != '\0')
	{
		if (***format == '#' && !s_dir->s_prct.is_sharp)
			s_dir->s_prct.is_sharp = 1;
		if (***format == '+' && !s_dir->s_prct.is_plus)
			s_dir->s_prct.is_plus = 1;
		if (***format == '-' && !s_dir->s_prct.is_minus)
			s_dir->s_prct.is_minus = 1;
		if (***format == '0' && !s_dir->s_prct.is_zero)
			s_dir->s_prct.is_zero = 1;
		s_dir->flag_count++;
		**format += 1;
	}
	while (ft_isdigit(***format) && ***format != '\0')
	{
		if (!s_dir->s_prct.is_set_adr)
		{
			s_dir->s_prct.adr = (char *)**format;
			s_dir->s_prct.is_set_adr = 1;
		}
		s_dir->digit_count++;
		**format += 1;
	}
}
