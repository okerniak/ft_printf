/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_create_string_wchar.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:55:23 by okerniak          #+#    #+#             */
/*   Updated: 2017/02/02 17:29:30 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static wchar_t		*ft_useflagi_wchar(t_flagi *flagi, wchar_t *ws)
{
	size_t	len;
	int		i;
	wchar_t	*str_add;
	wchar_t	*str_del;

	len = ft_strlen_wchar(ws);
	str_del = ws;
	if (flagi->point == 1 && flagi->accuracy < (int)len)
	{
		len = flagi->accuracy;
		ws[len] = 0;
	}
	if (flagi->width > (int)len)
	{
		str_add = (wchar_t*)malloc(sizeof(wchar_t) * (flagi->width - len + 1));
		i = 0;
		while (i < flagi->width - (int)len)
			str_add[i++] = ' ';
		str_add[i] = 0;
		ws = (flagi->minus == 1) ? ft_strjoin_wchar(ws, str_add) :
			ft_strjoin_wchar(str_del, ws);
		free(str_add);
		free(str_del);
	}
	return (ws);
}

wchar_t				*create_string_wchar(t_flagi *flagi, va_list p)
{
	wchar_t		*ws;
	int			i;

	i = 0;
	if ((flagi->tipe == 'c' && flagi->tipe_long[0] == 'l') ||
			flagi->tipe == 'C')
	{
		ws = (wchar_t*)malloc(sizeof(wchar_t) * 2);
		ws[0] = va_arg(p, wchar_t);
		ws[1] = '\0';
	}
	else
		ws = ft_strdup_wchar(va_arg(p, wchar_t*));
	ws = ft_useflagi_wchar(flagi, ws);
	return (ws);
}

int					len_simvol_show(t_flagi *flagi, void *str)
{
	int		count;

	if (ft_strchr("SC", flagi->tipe) || (ft_strchr("cs", flagi->tipe) &&
				flagi->tipe_long[0] == 'l'))
	{
		count = 0;
		while (((char*)str)[count] != 0)
			count++;
		ft_putstr_wchar(str);
	}
	else
	{
		count = ft_strlen(str);
		ft_putstr(str);
	}
	return (count);
}
