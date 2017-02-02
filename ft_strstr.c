/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:35:46 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/03 13:35:06 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		q;

	i = -1;
	j = 0;
	while (big[++i] && little[j])
		if (big[i] == little[0])
		{
			j = 0;
			q = i;
			while (big[q] == little[j] && little[j] != '\0')
			{
				q++;
				j++;
			}
		}
	if (big[i] == '\0' && little[j] != '\0')
		return (NULL);
	if (i != 0)
		i--;
	return ((char*)&big[i]);
}
