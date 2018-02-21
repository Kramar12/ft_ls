#include "ft_ls.h"


int     ls_tkfls(t_exls *ext, char **av)
{
	*av++;
	if (**av == '-' && (*av)++)
		while (**av)
		{
			if (**av == 'l' && (!((ext->flags / 1) % 2)))
				*av = (ext->flags += 1) ? ++(*av) : *av;
			if (**av == 'a' && (!((ext->flags / 10) % 2)))
				*av = (ext->flags += 10) ? ++(*av) : *av;
			if (**av == 'r' && (!((ext->flags / 100) % 2)))
				*av = (ext->flags += 100) ? ++(*av) : *av;
			if (**av == 'R' && (!((ext->flags / 1000) % 2)))
				*av = (ext->flags += 1000) ? ++(*av) : *av;
			if (**av == 't' && (!((ext->flags / 10000) % 2)))
				*av = (ext->flags += 10000) ? ++(*av) : *av;
			if (!**av)
			{
				*av++;
				if (**av != '-')
					break ;
				else
					(*av)++;
			}
		}
	while (**av != '.')
		*av--;
	return (0);
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
	*new = (t_exls){0, 0, 0, 1000000, 0, 0}; //alrRt1
	return (new);
}