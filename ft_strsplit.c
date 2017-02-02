/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:23:56 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/07 13:13:16 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strclen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

static int	ft_cwords(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[0] != c && ft_strlen(s) != 0)
		j++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**ret;
	int		count;

	i = 0;
	if (!s)
		return (0);
	count = ft_cwords(s, c);
	ret = (char **)malloc(sizeof(char*) * (count + 1));
	if (!ret)
		return (0);
	while (i < count)
	{
		while (*s == c && *s != '\0')
			s++;
		ret[i] = ft_strsub(s, 0, ft_strclen(s, c));
		if (!ret[i])
			return (0);
		s += ft_strclen(s, c);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
