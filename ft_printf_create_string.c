/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_create_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:50:35 by okerniak          #+#    #+#             */
/*   Updated: 2017/02/02 17:27:21 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_string_xxoouup(t_flagi *flagi, va_list p)
{
	int	base;

	base = 10;
	if (ft_strchr("xXoOp", flagi->tipe))
		base = (flagi->tipe == 'o' || flagi->tipe == 'O') ? 8 : 16;
	if (flagi->tipe_long[0] == 'h' && flagi->tipe_long[1] == 'h')
		return (ft_itoa_base_unsigned((unsigned char)va_arg(p, int), base));
	else if ((flagi->tipe_long[0] == 'l' && flagi->tipe_long[1] == 'l') ||\
			flagi->tipe == 'p')
		return (ft_itoa_base_unsigned(va_arg(p, unsigned long long int), base));
	else if (flagi->tipe_long[0] == 'h' && flagi->tipe != 'U')
		return (ft_itoa_base_unsigned((unsigned short)va_arg(p, int), base));
	else if (flagi->tipe_long[0] == 'l' || flagi->tipe == 'O' ||\
			flagi->tipe == 'U' || flagi->tipe == 'p')
		return (ft_itoa_base_unsigned(va_arg(p, unsigned long int), base));
	else if (flagi->tipe_long[0] == 'j')
		return (ft_itoa_base_unsigned(va_arg(p, uintmax_t), base));
	else if (flagi->tipe_long[0] == 'z')
		return (ft_itoa_base_unsigned(va_arg(p, size_t), base));
	else
		return (ft_itoa_base_unsigned(va_arg(p, unsigned int), base));
}

static char	*create_string_ddi(t_flagi *flagi, va_list p)
{
	if (flagi->tipe_long[0] == 'h' && flagi->tipe_long[1] == 'h')
		return (ft_itoa_base((signed char)va_arg(p, int), 10));
	else if (flagi->tipe_long[0] == 'l' && flagi->tipe_long[1] == 'l')
		return (ft_itoa_base(va_arg(p, long long int), 10));
	else if (flagi->tipe_long[0] == 'h')
		return (ft_itoa_base((signed short)va_arg(p, int), 10));
	else if (flagi->tipe_long[0] == 'l' || flagi->tipe == 'D')
		return (ft_itoa_base(va_arg(p, long int), 10));
	else if (flagi->tipe_long[0] == 'j')
		return (ft_itoa_base(va_arg(p, intmax_t), 10));
	else if (flagi->tipe_long[0] == 'z')
		return (ft_itoa_base(va_arg(p, size_t), 10));
	else
		return (ft_itoa_base(va_arg(p, int), 10));
}

static char	*ft_strdup_nul(char *str, t_flagi *flagi)
{
	if (ft_strchr("sS", flagi->tipe) && str == NULL)
		return (ft_strdup("(null)"));
	else if (ft_strchr("cCsSp", flagi->tipe) && (str == NULL || str[0] == '\0'))
	{
		str = (char*)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	else
		return (ft_strdup(str));
}

static char	*create_string_sc(t_flagi *flagi, va_list p)
{
	char	c[2];
	int		i;

	i = -1;
	if (flagi->tipe == 'c' && flagi->tipe_long[0] != 'l')
	{
		c[0] = va_arg(p, int);
		c[1] = '\0';
		return (ft_strdup_nul(c, flagi));
	}
	else
		return (ft_strdup_nul(va_arg(p, char*), flagi));
}

void		*create_string(t_flagi *flagi, va_list p, int *count)
{
	char		*str;

	if (flagi->tipe == '%')
		str = ft_strdup("%");
	else if (ft_strchr("xXoOuUp", flagi->tipe))
		str = create_string_xxoouup(flagi, p);
	else if (ft_strchr("dDi", flagi->tipe))
		str = create_string_ddi(flagi, p);
	else if (ft_strchr("sc", flagi->tipe) && flagi->tipe_long[0] != 'l')
		str = create_string_sc(flagi, p);
	else if (ft_strchr("sSCc", flagi->tipe))
		str = (char*)create_string_wchar(flagi, p);
	else
		str = ft_strdup("\0");
	if (flagi->tipe == 'p' && str[0] == '0' && flagi->accuracy == 0 &&
			flagi->point == 1)
		str[0] = '\0';
	if (str[0] == '\0' && ft_strchr("cC", flagi->tipe))
		*count = 1;
	if (str[0] == '\0' && ft_strchr("cC", flagi->tipe) && flagi->minus == 1)
		write(1, "\0", 1);
	if (!ft_strchr("SC", flagi->tipe) && !(ft_strchr("sc", flagi->tipe) &&
				flagi->tipe_long[0] == 'l'))
		str = ft_useflagi(str, flagi);
	return (str);
}
