
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

// using ls with the -R flag
// display the files and directories of the current directory
// from the directory 1 found, use the ls function again
// to display files and directories of the directory 1
// 

int main(int argc, char **argv)
{
    /*
    ** Pointer for directory entry
    */
    struct dirent *de;
    DIR *dr;
    char *dir_nm = ".";
    int R_flag = 0;

    if (argc >= 2)
    {
        if(!ft_strcmp(argv[1],"-R"))
        {
            R_flag = 1;
            ft_printf("RECURSIVE ACTIVATED\n");
            dir_nm = argv[2];
        }
        else
        {

            dir_nm = argv[1];
        }
    }

    /*
    ** open directory descriptor 
    ** (similar to file descriptor, instead with directories)
    */
    dr = opendir(dir_nm);
    if (dr == NULL)
    {
        // IMPORTANT: go to var_len in ft_printf, to check how to free any leaks with str and ints and format
        ft_printf("ft_ls: %s: %s\n", dir_nm, strerror(errno));
        return (0);
    }

    while ((de = readdir(dr)) != NULL)
    {
        ft_printf("%s\n", de->d_name);
    }
    return (0);
}

