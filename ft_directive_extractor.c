/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directive_extractor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:37:39 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/02 20:14:04 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_allocate(t_directives *s_dir)
{
	int	directive_size;

	directive_size = 10;
	if (s_dir->flag_count)
		directive_size += (s_dir->flag_count - 1);
	if (s_dir->digit_count)
		directive_size += (s_dir->digit_count - 1);
	if (s_dir->precision_count)
		directive_size += (s_dir->precision_count - 1);
	s_dir->raw_dir = (char *)malloc(sizeof(char) * directive_size);
	if (!s_dir->raw_dir)
		s_dir->raw_dir = NULL;
}

static void	ft_manager1(t_directives *s_dir, int *i)
{
	if (s_dir->flag_count)
	{
		while (s_dir->flag_count > 0)
		{
			(s_dir->raw_dir)[*i] = *(s_dir->dir_start);
			*i += 1;
			s_dir->dir_start += 1;
			s_dir->flag_count -= 1;
		}
		(s_dir->raw_dir)[*i] = '|';
		*i += 1;
	}
	else
	{
		(s_dir->raw_dir)[*i] = '@';
		*i += 1;
		(s_dir->raw_dir)[*i] = '|';
		*i += 1;
	}
}

static void	ft_manager2(t_directives *s_dir, int *i)
{
	if (s_dir->digit_count)
	{
		while (s_dir->digit_count > 0)
		{
			s_dir->raw_dir[*i] = *s_dir->dir_start;
			*i += 1;
			s_dir->dir_start += 1;
			s_dir->digit_count -= 1;
		}
		(s_dir->raw_dir)[*i] = '|';
		*i += 1;
	}
	else
	{
		(s_dir->raw_dir)[*i] = '@';
		*i += 1;
		(s_dir->raw_dir)[*i] = '|';
		*i += 1;
	}
}

static void	ft_manager3(t_directives *s_dir, int *i)
{
	if (s_dir->is_dot)
	{
		(s_dir->raw_dir)[*i] = *(s_dir->dir_start);
		*i += 1;
		s_dir->dir_start += 1;
		(s_dir->raw_dir)[*i] = '|';
		*i += 1;
	}
	else
	{
		(s_dir->raw_dir)[*i] = '@';
		*i += 1;
		(s_dir->raw_dir)[*i] = '|';
		*i += 1;
	}
}

void	ft_directive_extractor(t_directives *s_dir)
{
	int	i;

	ft_allocate(s_dir);
	i = 0;
	ft_manager1(s_dir, &i);
	ft_manager2(s_dir, &i);
	ft_manager3(s_dir, &i);
	if (s_dir->precision_count)
	{
		while (s_dir->precision_count > 0)
		{
			s_dir->raw_dir[i++] = *s_dir->dir_start++;
			s_dir->precision_count -= 1;
		}
		(s_dir->raw_dir)[i++] = '|';
	}
	else
	{
		s_dir->raw_dir[i] = '@';
		i++;
		s_dir->raw_dir[i] = '|';
		i++;
	}
	s_dir->raw_dir[i++] = *s_dir->dir_start;
	s_dir->raw_dir[i] = '\0';
}
