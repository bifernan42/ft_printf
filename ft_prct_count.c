/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prct_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:35:52 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/12 14:37:39 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prct_count(const char *format)
{
	int	prct_count;

	prct_count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			prct_count++;
		format++;
	}
	return (prct_count);
}
