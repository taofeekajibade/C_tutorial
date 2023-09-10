#include "main.h"

char *get_path(char *usercmd)
{
    char *path, *path_cpy, *path_tok, *file_path;
    int usercmd_len, dir_len;
    struct stat buffer;

    path = getenv("PATH");

    if (path)
    {
        path_cpy = strdup(path);
        usercmd_len = str_len(usercmd);
        path_tok = strtok(path_cpy, ":");

        while (path_tok != NULL)
        {
            dir_len = str_len(path_tok);
            file_path = malloc(usercmd_len + dir_len +2);
            strcpy(file_path, path_tok);
            strcat(file_path, "/");
            strcat(file_path, usercmd);
            strcat(file_path, "\0");

            if (stat(file_path, &buffer) == 0)
            {
                free(path_cpy);
                return (file_path);
            }
            else
            {
                free(file_path);
                path_tok = strtok(NULL, ":");
            }
        }
        free(path_cpy);
        if (stat(usercmd, &buffer) == 0)
        {
            return (usercmd);
        }
        return (NULL);
    }
    return (NULL);
}