/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:42:00 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/08 10:51:27 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrevers(char *str)
{
	char	*str2;
	int		i;

	i = 0;
	while (str[i])
		i++;
	str2 = (char*)malloc(sizeof(char) * i);
	str2[i] = '\0';
	i--;
	while (i >= 0)
	{
		str2[i] = *str;
		str++;
		i--;
	}
	return (str2);
}
