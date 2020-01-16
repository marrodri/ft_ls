

#include "ft_ls.h"

/*
** for sort in alphabetical order
*/

int	is_rsorted(char *a, char *b)
{
	if (ft_strcmp(a, b) > 0)
		return (1);
	return (0);
}

/*
** for sort in reverse order
*/

int	is_sorted(char *a, char *b)
{
	if (ft_strcmp(a, b) < 0)
		return (1);
	return (0);
}

char **ft_sortwords(char **words, int (*f)(char *a, char *b))
{
	char tmp[255];
	int i;
	int j;

	i = 0;
	j = 0;
	while(words[i])
	{
		j = i + 1;
		while(words[j])
		{
			if(f(words[i], words[j]))
			{
				ft_strcpy(tmp,words[i]);
				ft_strcpy(words[i], words[j]);
				ft_strcpy(words[j],tmp);
			}
			j++;
		}
		i++;
	}
	return words;
}