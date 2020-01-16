
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



// int flag_check_ls(char **av)
// {

// }

// int main(int ac, char **av)
// {
//     /*
//     ** window/terminal size structure. 
//     ** The winsize is accessed from the kernel
//     */

//     struct winsize w;

//     /*
//     ** 
//     */
//     ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

//     ft_printf("lines %d\n", w.ws_row);
//     ft_printf("columns %d\n", w.ws_col);
//     return 0;
// }

int ft_ls(t_app **app,struct dirent *de, DIR *dr)
{
    char *str;
    int len;
    int check;
    char **words;
    check = 0;
    len = 0;
    str = ft_strnew(1);
    while ((de = readdir(dr)) != NULL)
    {
        //move this to output list
        if ('.' != de->d_name[0])
        {
            if ((*app)->hi_len < (len = ft_strlen(de->d_name)))
            {
                (*app)->hi_len = len;
                ft_printf("new len is %d\n", len);
            }
            str = ft_strjoin(de->d_name, str);
            str = ft_strjoin(" ", str);
        }
    }

    ft_printf("%s\n", str);
    words = ft_strsplit(str, ' ');
    int i = 0;
    while (words[i])
    {
        ft_printf("word is |%s|\n", words[i]);
        i++;
    }
    words = ft_sortwords(words, is_rsorted);
    ft_printf("after sorting\n");
    i =0;
    while (words[i])
    {
        ft_printf("word is |%s|\n", words[i]);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    /*
    ** Pointer for directory entry
    */
    struct dirent *de;
    t_app *app;
    DIR *dr;
    char *dir_nm = ".";
    int R_flag = 0;
    app = malloc(sizeof(t_app));
    app->hi_len = 0;
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
    ft_ls(&app ,de, dr);
    return (0);
}

