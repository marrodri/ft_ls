/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:26:30 by marrodri          #+#    #+#             */
/*   Updated: 2020/01/16 13:26:32 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_output(t_app *app, t_tree *ls_tree, char *cur_direct)
{
	if (app->option_ch[0])
	{
		ft_printf("%s:\n", cur_direct);
	}
	if (ls_tree)
	{
		if (app->option_ch[2])
		{
			print_content_tree(app, ls_tree->root, print_l_format);
		}
		else
		{
			print_content_tree(app, ls_tree->root, print_file_name);
		}
	}
	ft_printf("\n");
}
