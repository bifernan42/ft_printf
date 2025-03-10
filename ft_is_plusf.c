/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_plusf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:26:58 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/02 19:27:04 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_plusf(const char *flags)
{
	while (*flags != '\0')
	{
		if (*flags == '+')
			return (1);
		flags++;
	}
	return (0);
}
