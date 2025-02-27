/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setstruct_prct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:57:43 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/15 15:18:55 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_setstruct_prct(t_prct *s_prct)
{
	s_prct->adr = NULL;
	s_prct->is_sharp = 0;
	s_prct->is_plus = 0;
	s_prct->is_minus = 0;
	s_prct->is_zero = 0;
	s_prct->is_set_adr = 0;
}
