/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:34:53 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/06 12:47:26 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*list1;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	list1 = f(tmp);
	list = list1;
	while (tmp->next)
	{
		tmp = tmp->next;
		list1->next = f(tmp);
		list1 = list1->next;
	}
	list1->next = NULL;
	return (list);
}
