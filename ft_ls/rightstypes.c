#include "ft_ls.h"

void	ls_rights(char *name, int type, int flags)
{
	struct stat sb;
	int			rg;
	int 	temp;
	int     counter;

	counter = 0;
	if (lstat(name, &sb) == -1)
		return ;
	rg = sb.st_mode;
	while (rg >= 4096)
		rg -= 4096;
	rg -= ((temp = rg / 64) != -42) ? temp * 64 : 0;
	ls_pr_type(type, flags, sb.st_blocks);
	while (counter++ < 3)
	{
		(temp >= 4 && (temp -= 4) != -42 )? write(1, "r", 1) : write(1, "-", 1);
		(temp >= 2 && (temp -= 2) != -42 )? write(1, "w", 1) : write(1, "-", 1);
		(temp >= 1 && (temp -= 1) != -42 )? write(1, "x", 1) : write(1, "-", 1);
		if (!temp)
			if (rg >= 8)
				rg -= ((temp = rg / 8) != -42) ? temp * 8 : 0;
			else if (rg && !(counter % 2) && (temp = rg) != -42)
				rg = 0;
	}
}
//valueLen = getxattr(path, buff, 1024,0, XATTR_SIZE);
void	ls_pr_type(int type, int flags, int blocks)
{
	if (flags / 100000 % 2)
		ft_printf("\n%d ", blocks);
	else
		write(1, "\n", 1);
	if (type == DT_FIFO)
		write(1, "p", 1);
	else if (type == DT_CHR)
		write(1, "c", 1);
	else if (type == DT_DIR)
		write(1, "d", 1);
	else if (type == DT_REG)
		write(1, "-", 1);
	else if (type == DT_LNK)
		write(1, "l", 1);
	else if (type == DT_SOCK)
		write(1, "s", 1);
}

int countargs(DIR dir, struct dirent *entry)		//count of objects in dir
{
	int     counter;

	counter = (entry && *entry->d_name != '.') ? 1 : 0;
	while (entry)
		counter += ((entry = readdir(&dir)) && *entry->d_name != '.') ? 1 : 0;
	return (counter);
}