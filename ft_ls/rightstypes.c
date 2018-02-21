#include "ft_ls.h"

void	ls_rights(char *name)
{
	struct stat sb;
	int			rg;
	int 		kat;

	kat = 0;
	if (stat(name, &sb) == -1)
		return ;
	if (sb.st_mode >= 4096 && sb.st_mode <= 4607)
		rg = sb.st_mode - 4096;
	else if (sb.st_mode >= 8192 && sb.st_mode <= 8703)
		rg = sb.st_mode - 8192;
	else if (sb.st_mode >= 16384 && sb.st_mode <= 16895)
		rg = sb.st_mode - 16384;
	else if (sb.st_mode >= 24576 && sb.st_mode <= 25087)
		rg = sb.st_mode - 24576;
	else if (sb.st_mode >= 32768 && sb.st_mode <= 33279)
		rg = sb.st_mode - 32768;
	else if (sb.st_mode >= 49152 && sb.st_mode <= 49663)
		rg = sb.st_mode - 49152;
	else
		return ;
	while (rg / 64 && ++kat)
		rg -= 64;
	kat *= 10;
	while (rg / 8 && ++kat)
		rg -= 8;
	kat = kat * 10 + rg;
	ls_prrgh(kat);
}

void	ls_pr_type(int type)
{
	if (type == DT_FIFO)
		printf("\np");
	else if (type == DT_CHR)
		printf("\nc");
	else if (type == DT_DIR)
		printf("\nd");
	else if (type == DT_REG)
		printf("\n-");
	else if (type == DT_LNK)
		printf("\nl");
	else if (type == DT_SOCK)
		printf("\ns");
}

void	ls_prrgh(int laws)	// print rights
{
	int 	temp;
	int     counter;

	counter = 0;
	laws = ((laws / 100) * 64) + ((laws / 10) % 10 * 8) + laws % 10;
	laws -= ((temp = laws / 64) != -42) ? temp * 64 : 0;
	while (counter++ < 3)
	{
		(temp >= 4 && (temp -= 4) != -42 )? printf("r") : printf("-");
		(temp >= 2 && (temp -= 2) != -42 )? printf("w") : printf("-");
		(temp >= 1 && (temp -= 1) != -42 )? printf("x") : printf("-");
		if (!temp)
			if (laws >= 8)
				laws -= ((temp = laws / 8) != -42) ? temp * 8 : 0;
			else if (laws && (temp = laws) != -42)
				laws = 0;
	}
}



int countargs(DIR dir, struct dirent *entry)		//count of objects in dir
{
	int     counter;

	counter = (entry && *entry->d_name != '.') ? 1 : 0;
	while (entry)
		counter += ((entry = readdir(&dir)) && *entry->d_name != '.') ? 1 : 0;
	return (counter);
}