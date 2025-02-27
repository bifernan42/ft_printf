/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directive_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:26:49 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/15 16:14:21 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_isdot(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static void	ft_manager1(t_directives *s_dir, int *char_count)
{
	s_dir->percent_count /= 2;
	while (s_dir->percent_count > 0)
	{
		ft_putchar('%', char_count);
		s_dir->percent_count--;
	}
}

static int	ft_manager2(t_directives *s_dir, int *char_count, \
const char **format, const char *options)
{
	ft_setstruct_prct(&(s_dir->s_prct));
	while (s_dir->percent_count > 0)
	{
		ft_putchar('%', char_count);
		s_dir->percent_count--;
	}
	ft_managerwhile(&format, s_dir, options);
	if (ft_isdot(**format))
	{
		s_dir->is_dot = 1;
		*format += 1;
		while (ft_isdigit(**format) && **format != '\0')
		{
			s_dir->precision_count++;
			*format += 1;
		}
	}
	if (!ft_isfcode(**format, "cspdiuxX%") || **format == '\0')
		return (0);
	return (1);
}

char	*ft_directive_handler(const char *format, int *char_count, \
t_directives *s_dir, va_list *adpar)
{
	ft_structsetter(s_dir);
	ft_whilepercent(&format, s_dir);
	s_dir->saved_prct_count = s_dir->percent_count;
	s_dir->dir_start = (char *)format;
	if (!(s_dir->percent_count % 2))
	{
		ft_manager1(s_dir, char_count);
		return ((char *)format);
	}
	else if (s_dir->percent_count % 2)
	{
		s_dir->percent_count /= 2;
		if (ft_manager2(s_dir, char_count, &format, s_dir->options))
		{
			ft_directive_extractor(s_dir);
			ft_setdirectives(s_dir);
			ft_specifier_handler(*s_dir, char_count, adpar);
			free((void *)s_dir->flags);
			format++;
		}
		else
			format = ft_handlermanager(format, char_count, s_dir);
	}
	return ((char *)format);
}
