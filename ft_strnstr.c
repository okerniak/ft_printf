/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:54:39 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/03 13:55:36 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int		i;
	int					j;
	unsigned int		q;

	i = 0;
	j = 0;
	while (big[i] && little[j] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			q = i;
			while (big[q] == little[j] && little[j] != '\0' && q < len)
			{
				j++;
				q++;
			}
		}
		i++;
	}
	if (little[j] != '\0')
		return (NULL);
	if (i != 0)
		i--;
	return ((char*)&big[i]);
}
