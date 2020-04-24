/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls_tree_comp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:26:30 by marrodri          #+#    #+#             */
/*   Updated: 2020/01/16 13:26:32 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** default comparison
*/

int	alphanum_comp(t_file_data *file1, t_file_data *file2)
{
	return (ft_strcmp(file1->file_name, file2->file_name) > 0);
}

/*
** default comparison
** r flag use this comp
*/

int	rev_alphanum_comp(t_file_data *file1, t_file_data *file2)
{
	return (ft_strcmp(file1->file_name, file2->file_name) < 0);
}

/*
** t flag use this comp
** add the current path to this function for the Rt flag
*/

int	file_date_comp(t_file_data *file1, t_file_data *file2)
{
	if (file1->mod_time == file2->mod_time)
	{
		return (alphanum_comp(file1, file2));
	}
	return ((file1->mod_time - file2->mod_time) < 0);
}

/*
** when rt flags are used
*/

int	rev_file_date_comp(t_file_data *file1, t_file_data *file2)
{
	if (file1->mod_time == file2->mod_time)
	{
		return (alphanum_comp(file1, file2));
	}
	return ((file1->mod_time - file2->mod_time) > 0);
}
