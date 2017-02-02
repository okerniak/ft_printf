/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:29:18 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/07 15:02:18 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char const *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	if (end < start || !s)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	while (start < end && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
