/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:12:49 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/03 13:28:00 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		f;

	i = 0;
	f = -1;
	while (s[i])
	{
		if (s[i] == c)
			f = i;
		i++;
	}
	if (c == '\0')
		return ((char*)s + i);
	if (f == -1)
		return (NULL);
	return ((char*)s + f);
}
