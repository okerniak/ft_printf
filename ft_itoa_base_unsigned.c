/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:54:45 by okerniak          #+#    #+#             */
/*   Updated: 2017/01/28 12:38:41 by okerniak         ###   ########.fr       */
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

char		*ft_itoa_base_unsigned(unsigned long long n, int base)
{
	char	*str;
	int		i;

	if (base < 2 || base > 16 || !(str = (char*)malloc(sizeof(char) * 100)))
		return (0);
	i = 0;
	ft_itoa_base_recursia(n, base, str, &i);
	str[i] = '\0';
	return (str);
}
