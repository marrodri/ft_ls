/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls_getstatus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:26:30 by marrodri          #+#    #+#             */
/*   Updated: 2020/01/16 13:26:32 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	is_directory(const char *path)
{
	struct stat		stat_buf;

	lstat(path, &stat_buf);
	return (S_ISDIR(stat_buf.st_mode));
}

int	is_regular_file(const char *file)
{
	struct stat path_stat;

	stat(file, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}
