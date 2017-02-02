/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:03:15 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/03 15:01:09 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char			*memory;
	unsigned int	i;

	if (size == 0)
		return (NULL);
	memory = (void*)malloc(size);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
