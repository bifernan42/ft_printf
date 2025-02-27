/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whilepercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:53:21 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/15 15:59:03 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_whilepercent(const char **format, t_directives *s_dir)
{
	while (ft_ispercent(**format))
	{
		s_dir->percent_count++;
		s_dir->prct_count--;
		(*format)++;
	}
}
