#include "libft/libft.h"
#include "libft/ft_printf.h"
#include <sys/types.h>
#include <dirent.h> // opendir, readdir, closedir
#include <sys/stat.h> //stat, lstat
#include <pwd.h> //getpwuid
#include <grp.h> //getgrgid
#include <sys/xattr.h> //listxattr, getxattr
#include <time.h> //time, ctime
// from unistd.h readlink
#include <errno.h> //perror, strerror
// exit()