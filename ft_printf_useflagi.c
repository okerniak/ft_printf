/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_useflagi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:10:22 by okerniak          #+#    #+#             */
/*   Updated: 2017/02/02 17:39:36 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_flagi_plus_spase_hash(char *str, t_flagi *flagi)
{
	char	*str_del;

	str_del = str;
	if (ft_strchr("dDi", flagi->tipe) && (flagi->plus == 1 || flagi->spase == 1)
			&& str[0] != '-')
		str = (flagi->plus == 1) ? ft_strjoin("+", str) : ft_strjoin(" ", str);
	else if (ft_strchr("xXoOp", flagi->tipe) && (flagi->hash == 1 ||
				flagi->tipe == 'p') && (str[0] != '0' || flagi->tipe == 'p'))
		str = ft_strjoin(((ft_strchr("oO", flagi->tipe)) ? "0" : "0X"), str);
	else
		return (str);
	ft_strdel(&str_del);
	return (str);
}

static char	*ft_flagi_accuracy_ddixxoouu(char *str, t_flagi *flagi, int len)
{
	char	*str_nul;
	int		i;
	char	*str_del;

	i = -1;
	str_nul = ft_strnew(flagi->accuracy - len);
	while (++i < flagi->accuracy - len)
		str_nul[i] = '0';
	if (ft_strchr("+- ", str[0]))
	{
		str_nul[0] = str[0];
		str[0] = '0';
	}
	if ((ft_strchr("xX", flagi->tipe) && flagi->hash == 1) ||
			flagi->tipe == 'p')
	{
		str_nul[1] = str[1];
		str[1] = '0';
	}
	str_del = str;
	str = ft_strjoin(str_nul, str);
	ft_strdel(&str_del);
	ft_strdel(&str_nul);
	return (str);
}

static char	*ft_flagi_accuracy(char *str, t_flagi *flagi)
{
	int	len;

	len = ft_strlen(str);
	if (flagi->accuracy == 0 && ft_strlen(str) <= 1 && str[0] == '0' &&\
			(flagi->hash != 1 || ft_strchr("xX", flagi->tipe)))
		str[0] = '\0';
	if (flagi->accuracy >= len && ft_strchr("dDixXoOuUp", flagi->tipe))
	{
		(str[0] == '-' || flagi->spase == 1 || flagi->plus == 1) ? len-- : 0;
		if ((ft_strchr("xX", flagi->tipe) && flagi->hash == 1) ||
				flagi->tipe == 'p')
			len -= 2;
		str = ft_flagi_accuracy_ddixxoouu(str, flagi, len);
	}
	if (ft_strchr("sScC", flagi->tipe) && flagi->accuracy < len)
		str[flagi->accuracy] = '\0';
	return (str);
}

static char	*ft_flagi_width(char *str, t_flagi *flagi, int len)
{
	char	c;
	char	*str_add;
	int		i;
	char	*str_del;

	c = (flagi->nul == 1 && flagi->minus != 1 &&
			(flagi->point == 0 || flagi->tipe == 'c')) ? '0' : ' ';
	str_add = ft_strnew(len);
	i = -1;
	while (++i < len)
		str_add[i] = c;
	if ((ft_strchr("+- ", str[0]) || flagi->hash == 1) &&\
			ft_strchr("dDixX", flagi->tipe) && c == '0')
	{
		i = (ft_strchr("xX", flagi->tipe) && flagi->hash == 1) ? 1 : 0;
		str_add[i] = str[i];
		str[i] = '0';
	}
	str_del = str;
	str = (flagi->minus == 1) ? ft_strjoin(str, str_add) :
		ft_strjoin(str_add, str);
	ft_strdel(&str_del);
	ft_strdel(&str_add);
	return (str);
}

char		*ft_useflagi(char *str, t_flagi *flagi)
{
	int		i;
	int		len;

	i = -1;
	if ((flagi->hash == 1 || flagi->spase == 1 || flagi->plus == 1 ||
				flagi->tipe == 'p') && ft_strchr("oOxXuUdDip", flagi->tipe))
		str = ft_flagi_plus_spase_hash(str, flagi);
	if (flagi->point == 1)
		str = ft_flagi_accuracy(str, flagi);
	if ((size_t)flagi->width > ft_strlen(str))
	{
		len = flagi->width - ft_strlen(str);
		(str[0] == '\0' && flagi->tipe == 'c') ? len-- : 0;
		str = ft_flagi_width(str, flagi, len);
	}
	if (flagi->tipe == 'x' || flagi->tipe == 'p')
		while (str[++i] != '\0')
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
	return (str);
}
