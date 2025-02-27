/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:36:26 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/02 20:15:37 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

void	ft_putstr(const char *str, int *char_count)
{
	while (*str != '\0')
	{
		write(1, str++, 1);
		*char_count += 1;
	}
}
