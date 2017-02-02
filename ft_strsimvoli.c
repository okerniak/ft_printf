/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsimvoli.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:34:55 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/08 11:53:34 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strsimvoli(const char *str, const char *simv)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != simv[j] && simv[j] != '\0')
			j++;
		if (simv[j] == '\0')
			return (0);
		i++;
	}
	return (1);
}
