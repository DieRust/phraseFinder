#ifndef _MYLIB
#define _MYLIB

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#define SIZE_OF_BUFFER 100
#define ERROR_EXIT -1
#define SUCCES_EXIT 0
#define FILE_ID 8
#define DIR_ID 4

typedef struct
{
    int number_of_line;
    int number_of_col;
}Data_about_line;


typedef struct
{
    int len_of_string;
    char string[SIZE_OF_BUFFER];
}string_data;

void search_in_buffer(string_data,char*,int,Data_about_line,int*);

#endif