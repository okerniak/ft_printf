/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:41:22 by okerniak          #+#    #+#             */
/*   Updated: 2017/02/02 17:21:58 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*tipe_long(char *str)
{
	char	base[6][3];
	int		i;

	ft_strcpy(base[0], "ll");
	ft_strcpy(base[1], "l");
	ft_strcpy(base[2], "j");
	ft_strcpy(base[3], "z");
	ft_strcpy(base[4], "hh");
	ft_strcpy(base[5], "h");
	i = -1;
	while (++i <= 5)
	{
		if (ft_strstr(str, base[i]))
			return (ft_strdup(base[i]));
	}
	return (ft_strdup("\0\0\0"));
}

static int		accuracy(char *str)
{
	int		i;
	int		accur;

	i = -1;
	accur = 0;
	while (str[++i])
		if (str[i] == '.')
			accur = ft_atoi(&str[i + 1]);
	return (accur);
}

static t_flagi	*ft_fill_flagi(char *str)
{
	t_flagi	*flagi;
	char	*str_del;

	str_del = str;
	flagi = (t_flagi*)malloc(sizeof(t_flagi));
	flagi->tipe = str[ft_strlen(str) - 1];
	flagi->hash = (ft_strchr(str, '#')) ? 1 : 0;
	flagi->point = (ft_strchr(str, '.')) ? 1 : 0;
	flagi->minus = (ft_strchr(str, '-')) ? 1 : 0;
	flagi->plus = (ft_strchr(str, '+')) ? 1 : 0;
	flagi->spase = (ft_strchr(str, ' ')) ? 1 : 0;
	flagi->tipe_long = tipe_long(str);
	flagi->nul = 0;
	flagi->accuracy = accuracy(str);
	while (*str && !(ft_strchr("123456789", *str)))
		if (*str++ == '0' && flagi->minus != 1)
			flagi->nul = 1;
	flagi->width = (*str && *(str - 1) != '.') ? ft_atoi(str) : 0;
	ft_strdel(&str_del);
	return (flagi);
}

static int		show_string(t_flagi *flagi, va_list p)
{
	char	*str;
	int		count;
	int		c_nul;

	count = 0;
	c_nul = 0;
	if (ft_strchr("sSpdDioOuUxXcC%", flagi->tipe))
	{
		str = create_string(flagi, p, &count);
		c_nul = count;
		count += len_simvol_show(flagi, str);
		if (c_nul == 1 && flagi->minus != 1)
			write(1, "\0", 1);
		free(str);
		free(flagi->tipe_long);
		free(flagi);
	}
	else
	{
		ft_putchar(flagi->tipe);
		count++;
	}
	return (count);
}

int				ft_printf(const char *str, ...)
{
	int		j;
	va_list	p;
	int		count;
	t_flagi	*flagi;

	va_start(p, str);
	count = 0;
	while (*str)
		if (*str == '%' && str++)
		{
			j = 0;
			while (str[j] && ft_strchr("0123456789hljz#-+*. ", str[j]))
				j++;
			flagi = (str[j]) ? ft_fill_flagi(ft_strsub(str, 0, j + 1)) : 0;
			count += (str[j]) ? show_string(flagi, p) : 0;
			str += (str[j]) ? j + 1 : j;
		}
		else
		{
			(*str) ? ft_putchar(*str++) : 0;
			(*(str - 1)) ? count++ : 0;
		}
	va_end(p);
	return (count);
}
