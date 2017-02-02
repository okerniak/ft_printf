/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:10:19 by okerniak          #+#    #+#             */
/*   Updated: 2017/02/02 17:24:40 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_strjoin_wchar(wchar_t const *s1, wchar_t const *s2)
{
	int			i;
	int			i2;
	wchar_t		*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen_wchar(s1);
	i2 = ft_strlen_wchar(s2);
	str = (wchar_t*)malloc(sizeof(wchar_t) * (i + i2));
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
