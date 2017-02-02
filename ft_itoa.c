/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:12:09 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/07 13:29:04 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*nul(void)
{
	char	*str;

	str = (char*)malloc(2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char			*ft_itoa(int a)
{
	unsigned int	count;
	char			*str_num;
	unsigned int	aa;

	aa = a;
	count = ft_lennbr(a);
	if (a == 0)
		return (nul());
	else if (a < 0)
		aa = -((unsigned int)a);
	str_num = ft_strnew(count);
	if (!str_num)
		return (NULL);
	while (count && aa)
	{
		str_num[--count] = aa % 10 + '0';
		aa /= 10;
	}
	if (!str_num[0])
		str_num[0] = '-';
	return (str_num);
}
