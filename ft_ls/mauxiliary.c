#include "ft_ls.h"


int     ls_tkfls(int flags, char **av)
{
	*av++;
	if (*av && **av == '-' && (*av)++)
		while (**av)
		{
			if (**av == 'l' && (!((flags / 1) % 2)))
				*av = (flags += 1) ? ++(*av) : *av;
			else if (**av == 'a' && (!((flags / 10) % 2)))
				*av = (flags += 10) ? ++(*av) : *av;
			else if (**av == 'r' && (!((flags / 100) % 2)))
				*av = (flags += 100) ? ++(*av) : *av;
			else if (**av == 'R' && (!((flags / 1000) % 2)))
				*av = (flags += 1000) ? ++(*av) : *av;
			else if (**av == 't' && (!((flags / 10000) % 2)))
				*av = (flags += 10000) ? ++(*av) : *av;
			else if (**av == 's' && (!((flags / 100000) % 2)))
				*av = (flags += 100000) ? ++(*av) : *av;
			else if (**av == '1' && (!((flags / 1000000) % 2)))
				*av = (flags += 1000000) ? ++(*av) : *av;
			else
				ls_errors(*av, 1);
			if (!**av)
			{
				*av++;
				if (!*av || **av != '-')
					break ;
				else
					(*av)++;
			}
		}
	return (flags);
}



t_ls    *tlsnew(void)
{
	t_ls    *new;

	if (!(new = (t_ls *)malloc(sizeof(t_ls))))
	{
		free(new);
		return (NULL);
	}
	*new = (t_ls){0, 0, 0, 0, 0, 0, 0, 0, 0};
	return (new);
}

t_exls    *textlsnew(void)
{
	t_exls  *new;

	if (!(new = (t_exls *)malloc(sizeof(t_exls))))
	{
		free(new);
		return (NULL);
	}
	*new = (t_exls){0, 0, 0, 1000000, 0, 0, 0, 0, 0, 0, 0}; //alrRt1
	return (new);
}