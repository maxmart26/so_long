/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:44:16 by matorgue          #+#    #+#             */
/*   Updated: 2023/12/24 14:55:11 by matorgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coordonees	*ft_lstlast(t_coordonees *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_coordonees **lst, t_coordonees *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

t_coordonees	*ft_lstnew(int i, int j)
{
	t_coordonees	*new;

	new = malloc(sizeof(t_coordonees));
	if (new == NULL)
		return (NULL);
	new->i = i;
	new->j = j;
	new->next = NULL;
	return (new);
}

int	ft_is_new(t_coordonees *case_possible, int i, int j)
{
	while (case_possible != NULL)
	{
		if (i == case_possible->i && j == case_possible->j)
			return (0);
		case_possible = case_possible->next;
	}
	return (1);
}

void	ft_get_case_possible(char **map, int i, int j,
		t_coordonees **case_possible)
{
	if (map[i][j - 1] != '1' && ft_is_new(*case_possible, i, j - 1) == 1)
	{
		ft_lstadd_back(case_possible, ft_lstnew(i, j - 1));
		ft_get_case_possible(map, i, j - 1, case_possible);
	}
	if (map[i + 1][j] != '1' && ft_is_new(*case_possible, i + 1, j) == 1)
	{
		ft_lstadd_back(case_possible, ft_lstnew(i + 1, j));
		ft_get_case_possible(map, i + 1, j, case_possible);
	}
	if (map[i - 1][j] != '1' && ft_is_new(*case_possible, i - 1, j) == 1)
	{
		ft_lstadd_back(case_possible, ft_lstnew(i - 1, j));
		ft_get_case_possible(map, i - 1, j, case_possible);
	}
	if (map[i][j + 1] != '1' && ft_is_new(*case_possible, i, j + 1) == 1)
	{
		ft_lstadd_back(case_possible, ft_lstnew(i, j + 1));
		ft_get_case_possible(map, i, j + 1, case_possible);
	}
}
