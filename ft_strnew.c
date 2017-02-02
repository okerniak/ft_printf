/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:25:36 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/03 15:02:04 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	str = (char*)malloc(size + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	str[size] = '\0';
	return (str);
}
