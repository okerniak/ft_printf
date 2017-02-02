/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:08:25 by okerniak          #+#    #+#             */
/*   Updated: 2017/02/02 17:28:08 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_strdup_wchar(const wchar_t *s1)
{
	wchar_t	*str;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	str = (wchar_t*)malloc(sizeof(wchar_t) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
