/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:36:07 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/02 20:50:15 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar2(int c, int *char_count, t_directives s_dir)
{
	int	to_print;

	to_print = ' ';
	if (ft_is_minusf(s_dir.flags))
	{
		ft_putchar(c, char_count);
		s_dir.field_width -= 1;
		while (s_dir.field_width > 0)
		{
			ft_putchar(to_print, char_count);
			s_dir.field_width--;
		}
	}
	else
	{
		s_dir.field_width -= 1;
		while (s_dir.field_width > 0)
		{
			ft_putchar(to_print, char_count);
			s_dir.field_width--;
		}
		ft_putchar(c, char_count);
	}
}
