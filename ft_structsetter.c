/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structsetter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:34:01 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/12 14:59:03 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_structsetter(t_directives *s_dir)
{
	s_dir->options = "# +0-";
	s_dir->precision_count = 0;
	s_dir->is_space = 0;
	s_dir->zeroes = 0;
	s_dir->is_plus = 0;
	s_dir->dot = '@';
	s_dir->saved_prct_count = 0;
	s_dir->filler = ' ';
	s_dir->numberlen = 0;
	s_dir->percent_count = 0;
	s_dir->flag_count = 0;
	s_dir->digit_count = 0;
	s_dir->drawn_minus = 0;
	s_dir->precision = 0;
	s_dir->is_dot = 0;
	s_dir->dir_start = NULL;
	s_dir->raw_dir = NULL;
}
