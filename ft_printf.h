/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:56:56 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/15 16:16:48 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_prct
{
	int		is_sharp;
	int		is_plus;
	int		is_minus;
	int		is_zero;
	int		is_set_adr;
	char	*adr;
}	t_prct;

typedef struct s_directives
{
	const char	*flags;
	const char	*options;
	int			field_width;
	int			precision;
	int			zeroes;
	int			is_plus;
	int			is_space;
	int			flag_count;
	int			digit_count;
	int			precision_count;
	int			is_dot;
	int			percent_count;
	int			numberlen;
	int			drawn_minus;
	int			prct_switch;
	int			prct_count;
	int			saved_prct_count;
	int			ipc;
	char		filler;
	char		dot;
	char		specifier;
	char		*dir_start;
	char		*raw_dir;
	t_prct		s_prct;
}	t_directives;

typedef struct s_values
{
	char	*base_to;
	char	*result;
	char	*to_print;
	size_t	base_size;
}	t_values;

t_values	ft_convertbase(long number, int *id);

size_t		ft_strlen(const char *str);

int			ft_prct_count(const char *format);
int			ft_atoi(const char *str);
int			ft_printf(const char *format, ...)__attribute__ ((format \
(printf, 1, 2)));
int			ft_ispercent(char c);
int			ft_isfcode(char c, const char *fcodes);
int			ft_isflag(char c, const char *flags);
int			ft_is_minusf(const char *flags);
int			ft_is_zerof(const char *flags);
int			ft_is_plusf(const char *flags);
int			ft_is_spacef(const char *flags);
int			ft_is_hashtagf(const char *flags);

void		ft_miniputhex(char *hexnum, t_directives *s_dir, int *char_count);
void		ft_putstr(const char *str, int *char_count);
void		ft_putchar(int c, int *char_count);
void		ft_putstr2(const char *str, int *char_count, t_directives s_dir);
void		ft_putchar2(int c, int *char_count, t_directives s_dir);
void		ft_specifier_handler(t_directives s_dir, \
int *char_count, va_list *adpar);

void		ft_setdirectives(t_directives *s_dir);
void		ft_managerwhile(const char ***format, t_directives *s_dir, \
const char *options);
void		ft_putnbr(int nbr, int *char_count, t_directives s_dir);
void		ft_putunsigned_nbr(unsigned int nbr, \
int *char_count, t_directives s_dir);
void		ft_puthex(long number, int id, int *char_count, t_directives s_dir);
void		ft_structsetter(t_directives *s_dir);
void		ft_whilepercent(const char **format, t_directives *s_dir);
void		ft_directive_extractor(t_directives *s_dir);
void		ft_deallocate(char **array, int i);
void		ft_setstruct_prct(t_prct *s_prct);

char		**ft_split(char const *s, char c);

char		*ft_itoa(long n);
char		*ft_handlermanager(const char *format, \
int *char_count, t_directives *s_dir);
char		*ft_directive_handler(const char *format, \
int *char_count, t_directives *s_dir, va_list *adpar);

#endif
