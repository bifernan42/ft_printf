/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:12:12 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/04 20:18:24 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_idchecker(int id)
{
	if (id == 0)
		return ("0123456789abcdef");
	else if (id == 1)
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

static void	ft_setstring(char *adr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		adr[i] = 'f';
		i++;
	}
	adr[i] = '\0';
}	

static char	*ft_caf(int id)
{
	char	*allocated_memory;

	if (id == 0)
	{
		allocated_memory = (char *)malloc(sizeof(char) * 9);
		if (!allocated_memory)
			return (NULL);
		ft_setstring(allocated_memory, 9);
	}
	if (id == 1)
	{
		allocated_memory = (char *)malloc(sizeof(char) * 9);
		if (!allocated_memory)
			return (NULL);
		ft_setstring(allocated_memory, 9);
	}
	if (id == 2)
	{
		allocated_memory = (char *)malloc(sizeof(char) * 17);
		if (!allocated_memory)
			return (NULL);
		ft_setstring(allocated_memory, 17);
	}
	return (allocated_memory);
}

static char	*ft_nonsigzero(char *hexnum, int *i_ext)
{
	size_t	i;
	size_t	buffer_size;

	buffer_size = ft_strlen(hexnum);
	i = 0;
	if (hexnum[0] != '0')
		return (hexnum + *i_ext + 1);
	while (hexnum[i] == '0' && i < buffer_size -1)
		i++;
	return (&hexnum[i]);
}

t_values	ft_convertbase(long number, int *id)
{
	t_values	s_val;
	int			i;
	int			j;

	s_val.base_size = 16;
	s_val.base_to = ft_idchecker(*id);
	s_val.result = ft_caf(*id);
	if ((*id) == 2 && number == 0)
	{
		s_val.to_print = "(nil)";
		*id = 3;
		return (s_val);
	}
	i = ft_strlen(s_val.result) - 1;
	while (i >= 0)
	{
		j = number % s_val.base_size;
		s_val.result[i] = s_val.base_to[j];
		i--;
		number /= s_val.base_size;
	}
	s_val.to_print = ft_nonsigzero(s_val.result, &i);
	return (s_val);
}
