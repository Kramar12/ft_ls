#include <sys/acl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <termios.h>   //for tcgetattr
# include <errno.h>     //do i need this?
# include <sys/ioctl.h>
# include <stdarg.h>
#include <grp.h>


//
//int
//main(int argc, char *argv[])
//{
//
//
//	struct stat sb;
//
//	if (argc != 2) {
//		fprintf(stderr, "Usage: %s <pathname>\n", argv[1]);
//		exit(EXIT_FAILURE);
//	}
//
//	if (stat(argv[1], &sb) == -1) {
//		perror("stat");
//		exit(EXIT_FAILURE);
//	}
//	printf("File type:                ");
//
//	switch (sb.st_mode & S_IFMT) {
//		case S_IFBLK:  printf("block device\n");            break;
//		case S_IFCHR:  printf("character device\n");        break;
//		case S_IFDIR:  printf("directory\n");               break;
//		case S_IFIFO:  printf("FIFO/pipe\n");               break;
//		case S_IFLNK:  printf("symlink\n");                 break;
//		case S_IFREG:  printf("regular file\n");            break;
//		case S_IFSOCK: printf("socket\n");                  break;
//		default:       printf("unknown?\n");                break;
//	}
//
//	printf("I-node number:            %ld\n", (long) sb.st_ino);
//
//	printf("Mode:                     %lo (octal)\n",
//	       (unsigned long) sb.st_mode);
//
//	printf("Link count:               %ld\n", (long) sb.st_nlink);
//	printf("Ownership:                UID=%ld   GID=%ld\n",
//	       (long) sb.st_uid, (long) sb.st_gid);
//
//	printf("Preferred I/O block size: %ld bytes\n",
//	       (long) sb.st_blksize);
//	printf("File size:                %lld bytes\n",
//	       (long long) sb.st_size);
//	printf("Blocks allocated:         %lld\n",
//	       (long long) sb.st_blocks);
//	printf("Rights:                   %lld\n",
//	       (long long) sb.st_mode);
//
//	printf("Last status change:       %s", ctime(&sb.st_ctime));
//	printf("Last file access:         %s", ctime(&sb.st_atime));
//	printf("Last file modification:   %s", ctime(&sb.st_mtime));
//
//	exit(EXIT_SUCCESS);
//}



//
//int main (int ac, char **av) {
//	acl_t acl = NULL;
//	acl_entry_t dummy;
//	ssize_t xattr = 0;
//	char str[10];
//	char * filename = av[1];
//
//
//	acl_t acl = NULL;
//	acl_entry_t dummy;
//	if ((acl = acl_get_link_np(filename, ACL_TYPE_EXTENDED))
//	    && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
//	{
//		acl_free(acl);
//		acl = NULL;
//	}
//	xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
//	if (xattr < 0)
//		xattr = 0;
//
//	str[1] = '\0';
//	if (xattr > 0)
//		str[0] = '@';
//	else if (acl != NULL)
//		str[0] = '+';
//	else
//		str[0] = ' ';
//
//	printf("%s\n", str);
//}


int main ()
{
	printf("%hd", ft_p);

	return 0;
}