/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:18:11 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/06 12:58:35 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		i2;
	char	*str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	i2 = 0;
	while (s2[i2])
		i2++;
	str = (char*)malloc(i + i2);
	if (!str)
		return (NULL);
	i = -1;
	i2 = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++i2])
		str[i++] = s2[i2];
	str[i] = '\0';
	return (str);
}
