/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:39:05 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/02 14:41:51 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isfcode(char c, const char *fcodes)
{
	while (*fcodes != '\0')
	{
		if (c == *fcodes)
			return ((int)c);
		fcodes++;
	}
	return (0);
}
