#include "ft_ls.h"

void	ls_rights(char *name)
{
	struct stat sb;
	int			rg;
	int 	temp;
	int     counter;

	counter = 0;
	if (stat(name, &sb) == -1)
		return ;
	rg = sb.st_mode;
	while (rg >= 4096)
		rg -= 4096;
	rg -= ((temp = rg / 64) != -42) ? temp * 64 : 0;
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
void	ls_pr_type(int type)
{
	if (type == DT_FIFO)
		write(1, "\np", 2);
	else if (type == DT_CHR)
		write(1, "\nc", 2);
	else if (type == DT_DIR)
		write(1, "\nd", 2);
	else if (type == DT_REG)
		write(1, "\n-", 2);
	else if (type == DT_LNK)
		write(1, "\nl", 2);
	else if (type == DT_SOCK)
		write(1, "\ns", 2);
}

int countargs(DIR dir, struct dirent *entry)		//count of objects in dir
{
	int     counter;

	counter = (entry && *entry->d_name != '.') ? 1 : 0;
	while (entry)
		counter += ((entry = readdir(&dir)) && *entry->d_name != '.') ? 1 : 0;
	return (counter);
}