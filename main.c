
#include "ft_ls.h"

// ft_ls flags[- l,R,a,r,t] <dir default = ".">
// TODO recreate the ls function 
// with 
// -l, more detailed output
//  -R, recursive output
//  -a, display hidden files, ._* files
//  -r, reverse the list order
//-t, sorts by modification time, from the most current
// modified object to the oldest modified object

// start with -R at the beggining of all the flags
int main(int argc, char **argv)
{

    /* Pointer for directory entry */
    char *dir_nm = ".";
    struct dirent *de;
    DIR *dr;

    if (argc == 2)
        dir_nm = argv[1];


    dr = opendir(dir_nm); //open directory descriptor (similar to file descriptor, instead with directories)
    if (dr == NULL)
    {
        ft_printf("ft_ls: %s: No such file or directory", dir_nm);
        return (0);
    }

    while ((de = readdir(dr)) != NULL)
    {
        ft_printf("%s\n", de->d_name);
    }
    return (0);
}

// using ls with the -R flag
// display the files and directories of the current directory
// from the directory 1 found, use the ls function again
// to display files and directories of the directory 1
// 