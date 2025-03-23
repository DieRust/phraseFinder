#ifndef _MYLIB
#define _MYLIB

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#define SIZE_OF_BUFFER 1024
#define ERROR_EXIT -1
#define SUCCES_EXIT 0
#define FILE_ID 8
#define DIR_ID 4

typedef struct 
{
    int argc;
    char** argv;
}Data_from_user;


typedef struct
{
    int number_of_line;
    int number_of_col;
}Data_about_line;

typedef struct
{
    int len_of_string;
    char string[SIZE_OF_BUFFER];
}String_data;


int check_numbers_of_arguments(int);

int check_if_path_exits(Data_from_user);

int path_is_a_file(Data_from_user,FILE*);

int search_in_buffer(String_data, Data_from_user, Data_about_line);

int path_is_a_dir(Data_from_user,DIR*);

#endif