/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <ariabyi@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:09:00 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/23 20:09:00 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


t_ls 	*ls_sl_t(t_ls **root)	//sort list
{
	struct stat sb;
	struct stat sp;
	t_ls *temp;
	t_ls *current;
	ssize_t q;

	temp = NULL;
	current = *root;
	while (current)
	{}

}

void 	*ls_sl_r(t_ls **root)
{
	t_ls *temp;
	t_ls *current;

	temp = NULL;
	current = *root;
	while (current)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	*root = temp ? temp->prev : *root;
}

t_ls 	*ls_sl(t_ls *root)
{
	t_ls *new_root;
	t_ls *node;
	t_ls *cur;

	new_root = NULL;
	while (root)
	{
		node = root;
		root = root->next;
		if (!new_root ||	((node->nm && new_root->nm) && !(ft_strcmp(node->nm, new_root->nm))))
		{
			node->next = new_root;
			new_root = node;
		}
		else
		{
			cur = new_root;
			while (cur->next && ((node->nm && cur->next->nm) && (ft_strcmp(node->nm, cur->next->nm))))
				cur = cur->next;
			node->next = cur->next;
			if (node->nm)
				cur->next = node;
		}
	}
	return (new_root);
}
