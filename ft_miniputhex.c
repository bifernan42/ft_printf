/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miniputhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:20:09 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/05 17:37:02 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_miniputhex(char *hexnum, t_directives *s_dir, int *char_count)
{
	if (*hexnum == '0' && s_dir->field_width && s_dir->is_dot)
	{
		ft_putchar(' ', char_count);
		return ;
	}
	if (s_dir->is_dot && !s_dir->precision && *hexnum == '0')
	{
		if (ft_is_minusf(s_dir->flags))
			return ;
		if (ft_is_zerof(s_dir->flags))
			ft_putchar(' ', char_count);
		s_dir->field_width += 1;
		return ;
	}
	else
		ft_putstr(hexnum, char_count);
}
