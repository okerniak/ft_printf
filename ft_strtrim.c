/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:47:51 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/07 15:30:53 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	j = 0;
	while (s[j])
		j++;
	if (i == j)
		return (ft_strcut(s, i, j));
	j--;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	j++;
	return (ft_strcut(s, i, j));
}
