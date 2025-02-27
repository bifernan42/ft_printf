/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:39:37 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/15 15:28:47 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_directives	s_dir;
	int				char_count;
	va_list			adpar;
	char			*reader;	

	if (!format)
		return (-1);
	s_dir.prct_switch = 0;
	s_dir.prct_count = ft_prct_count(format);
	s_dir.ipc = s_dir.prct_count;
	char_count = 0;
	reader = (char *)format;
	va_start(adpar, format);
	while (*reader != '\0')
	{
		if (ft_ispercent(*reader))
			reader = ft_directive_handler(reader, &char_count, &s_dir, &adpar);
		else
		{
			ft_putchar(*reader, &char_count);
			reader++;
		}
	}
	va_end(adpar);
	return (char_count);
}
