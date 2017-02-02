/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:22:24 by okerniak          #+#    #+#             */
/*   Updated: 2017/01/27 15:16:39 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_base_recursia(unsigned long long n, int base,\
		char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789ABCDEF";
	if (n >= (unsigned long long)base)
		ft_itoa_base_recursia(n / base, base, str, i);
	str[(*i)++] = tmp[n % base];
}

char		*ft_itoa_base(long long nbr, int base)
{
	char				*str;
	int					i;
	unsigned long long	n;

	if (base < 2 || base > 16 || !(str = (char*)malloc(sizeof(char) * 32)))
		return (0);
	i = 0;
	if (nbr < 0 && base == 10)
		str[i++] = '-';
	n = (nbr < 0) ? -nbr : nbr;
	ft_itoa_base_recursia(n, base, str, &i);
	str[i] = '\0';
	return (str);
}
