/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:35:07 by okerniak          #+#    #+#             */
/*   Updated: 2017/01/25 14:39:25 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
