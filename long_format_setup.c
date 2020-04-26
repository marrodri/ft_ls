/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format_setup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:39:44 by marrodri          #+#    #+#             */
/*   Updated: 2020/03/04 15:39:46 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*filesize_to_string(off_t file_size)
{
	long int	bitsize;
	char		*bitsize_str;

	bitsize = (long int)file_size;
	bitsize_str = ft_llitoa_base(bitsize, 10);
	return (bitsize_str);
}

// alias winhome="cd /mnt/c/Users/marod\ bits"

// char	*user_and_group_to_string(nlink_t links, uid_t user_id, gid_t group_id)
// {
// 	char			*user_and_group_str;
// 	struct group	*grp_cont;
// 	struct passwd	*pw_cont;
// 	char			*tmp;

// 	grp_cont = getgrgid(group_id);
// 	pw_cont = getpwuid(user_id);
// 	user_and_group_str = ft_itoa(links);
// 	tmp = user_and_group_str;
// 	user_and_group_str = ft_strjoin(user_and_group_str, " ");
// 	free(tmp);
// 	tmp = user_and_group_str;
// 	user_and_group_str = ft_strjoin(user_and_group_str, pw_cont->pw_name);
// 	free(tmp);
// 	tmp = user_and_group_str;
// 	user_and_group_str = ft_strjoin(user_and_group_str, grp_cont->gr_name);
// 	free(tmp);
// 	return (user_and_group_str);
// }

char	*user_and_group_to_string(uid_t user_id, gid_t group_id)
{
	char			*user_and_group_str;
	struct group	*grp_cont;
	struct passwd	*pw_cont;
	char			*tmp;

	grp_cont = getgrgid(group_id);
	pw_cont = getpwuid(user_id);
	// user_and_group_str = ft_itoa(links);
	// user_and_group_str = pw_cont->pw_name;
	// tmp = user_and_group_str;
	user_and_group_str = ft_strjoin(pw_cont->pw_name, " ");
	tmp = user_and_group_str;

	// free(tmp);
	// tmp = user_and_group_str;
	// user_and_group_str = ft_strjoin(user_and_group_str, pw_cont->pw_name);
	// free(tmp);
	// tmp = user_and_group_str;
	user_and_group_str = ft_strjoin(user_and_group_str, grp_cont->gr_name);
	free(tmp);
	return (user_and_group_str);
}

char	*modified_time_to_string(time_t mod_time)
{
	char *readable_mtime_str;

	readable_mtime_str = ft_strdup(ctime(&mod_time));
	readable_mtime_str = str_char_replace(readable_mtime_str, '\n', ' ');
	return (readable_mtime_str);
}
