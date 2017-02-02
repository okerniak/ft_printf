/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strkillchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:09:44 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/08 12:27:20 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strkillchr(char *str, char c)
{
	char	*str2;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != c)
			j++;
	i = -1;
	j = 0;
	str2 = (char*)malloc(sizeof(char) * j + 1);
	while (str[++i])
		if (str[i] != c)
		{
			str2[j] = str[i];
			j++;
		}
	str2[j] = '\0';
	return (str2);
}
