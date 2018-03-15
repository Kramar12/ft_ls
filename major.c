#include "ft_ls.h"

#include "libft/ft_strcmp.c"
#include "libft/ft_mstrcmp.c"

void					get_time(char *place, t_exls *ext, char *name)
{
	char				*temp;
	struct stat			sb;
	struct passwd		*pw;
	struct group		*gr;
	char				buff[1024];

	lstat(place, &sb);
	ls_acl(place);
	if ((readlink(place, buff, 1024) != -1))
	{
		temp = ft_multjoin(3, name, " -> ", buff);
		name = ft_strdup(temp);
		free(temp);
	}
	pw  = getpwuid(sb.st_uid);
	gr = getgrgid(sb.st_gid);
	ft_printf("%*d %-*s  %-*s  ", ext->lenlinks + 1, sb.st_nlink, ext->lenowner, pw->pw_name, ext->lengroup, gr->gr_name);
	if (ext->dev || (S_ISBLK(sb.st_mode) || S_ISCHR(sb.st_mode)))
		(ext->dev = 1 ) ? ft_printf("%*llu, %*llu ", ext->lmaj, MAJOR(sb.st_rdev), ext->lmin, MINOR(sb.st_rdev)) : 0;
	else if (ext->dev)
		ft_printf("%*zu ",ext->lensize, sb.st_size);
	else
		ft_printf("%*zu ",ext->lensize, sb.st_size);
	ft_printf("%s %s", (temp = ft_strsub(ctime((const time_t  *)&sb.st_mtimespec), 4, 12)), name);
	free(temp);
}

void					ls_lpr(t_ls *root, t_exls *ext, int code)
{
	char				*dest;
	char				*temp;

	if (!ls_getwidth(root, ext))
		return ;
	((dest = NULL) || !ext->solo) && !code ? ft_printf("total %d\n", ext->total) : 0;
	while (root && root->nm)
	{
		if (*(temp = slovo(root->nm)) FLAG_A)
		{
			free(temp);
			if (*root->nm == '/' && root->nm[ft_strlen(root->nm) - 1] != '/')
				dest = ft_strdup(root->nm);
			if (!dest && ext->FLAG_R)
				dest = ft_multjoin(3, ext->dest, "/", root->nm);
			else if (!dest)
				dest = ft_strjoin(ext->dest, root->nm);
			ls_rights(dest, ext->flags, ext->block);
			get_time(dest, ext, root->nm);
			(root->next && root->next->nm) ? write(1, "\n", 1) : 0;
			dest ? free(dest) : 0;
			dest = NULL;
		}
		root = root->next;
	}
}

int					ls_getwidth(t_ls *root, t_exls *ext)	//для быстроты работы поставить условия на все операции которые нужны только для -l
{
	struct passwd		*pw;
	struct group		*gr;
	struct stat			sb;
	char				*place;
	char				*temp;

	if (ext->dest[ft_strlen(ext->dest) - 1] != '/')
	{
		temp = ft_strdup(ext->dest);
		free(ext->dest);
		ext->dest = ft_strjoin(temp, "/");
		free(temp);
	}
	while (root && root->nm)
	{
		temp = slovo(root->nm);
		if (*root->nm == '/')
			place = ft_strdup(root->nm);
		else
			place = ft_strjoin(ext->dest, root->nm);
		lstat(place, &sb);
		if ((pw = getpwuid(sb.st_uid)))
			ext->lenowner = pw && ft_strlen(pw->pw_name) > (size_t)ext->lenowner ? (int) (ft_strlen(pw->pw_name)) : ext->lenowner;
		if ((gr = getgrgid(sb.st_gid)))
			ext->lengroup = ft_strlen(gr->gr_name) > (size_t)ext->lengroup ? (int) (ft_strlen(gr->gr_name)) : ext->lengroup;
		if (!((sb.st_blksize < 0 || sb.st_rdev < 0) && !S_ISLNK(sb.st_mode)))
		{
			ext->total += sb.st_blocks;
			ext->lenlinks = ft_pwrbase(sb.st_nlink, 10) > ext->lenlinks ? ft_pwrbase(sb.st_nlink, 10) : ext->lenlinks;
			ext->lensize = ft_pwrbase(sb.st_size, 10) > ext->lensize ? ft_pwrbase(sb.st_size, 10) : ext->lensize;
			ext->block = ft_pwrbase(sb.st_blocks, 10) > ext->block ? ft_pwrbase(sb.st_blocks, 10) : ext->block;
			ext->wword = ft_strlen(root->nm) > (size_t) ext->wword ? (int) ft_strlen(root->nm) : ext->wword;
			ext->cword++;
			ext->lmaj = ft_pwrbase(MAJOR(sb.st_rdev), 10) > ext->lmaj ? ft_pwrbase(MAJOR(sb.st_rdev), 10) : ext->lmaj;
			ext->lmin = ft_pwrbase(MINOR(sb.st_rdev), 10) > ext->lmin ? ft_pwrbase(MINOR(sb.st_rdev), 10) : ext->lmin;
			root = root->next;
		}
		free(place);
		free(temp);
		if ((sb.st_blksize < 0 || sb.st_rdev < 0) && !S_ISLNK(sb.st_mode))
			return (0);
	}
	ext->elms = ext->cword;
	return (1);
}

void					ls_prnt(t_ls *root, t_exls *ext)
{
	int					i;
	char				*temp;
	char				*place;
	int 				tcword;


	temp = NULL;
	place = NULL;
	ls_getwidth(root, ext);
	tcword = ext->cword;
	while (!(i = 0) && ++ext->wword % 8);
	while (root && root->nm)
	{
		if (i + ext->wword > ext->wscol || ((i / ext->wword == ext->cword / 2 + 1 && ext->cword * ext->wword > ext->wscol)))
			i *= ft_printf("\n%-*s", ext->wword, root->nm) ? 0 : 0;
		else
			ft_printf("%-*s", ext->wword, root->nm);
		tcword--;
		free(temp);
		free(place);
		place = NULL;
		i += (root->nm && *(temp = slovo(root->nm)) FLAG_A) ? ext->wword : 0;
		root = root->next;
		temp ? free(temp) : 0;
		temp = NULL;
	}
}

