#include "mylib.h"

int main(int argc, char* argv[]){
    FILE* file;
    DIR* dir;
    struct dirent *entry;
    int count_of_found = 0;
    string_data buffer_of_file;
    Data_about_line data_about_line = {1,0};

    if(argc != 3){
        printf("wrong number of input\nyou should use this template: ./lab path search_txt\n");
        return ERROR_EXIT;
    }

    file = fopen(argv[1],"r");
    dir = opendir(argv[1]);

    if (file == NULL || dir == NULL){
        printf("you use wrong path\n");
        return ERROR_EXIT;
    }

    int len_of_search_text = strlen(argv[2]);
    char search_text[len_of_search_text];

    strcpy(search_text,argv[2]);
    if(file != NULL){
    while (fgets(buffer_of_file.string,SIZE_OF_BUFFER,file))
    {
        buffer_of_file.len_of_string = strlen(buffer_of_file.string);
        search_in_buffer(buffer_of_file, search_text, len_of_search_text, data_about_line, &count_of_found);
        if(buffer_of_file.len_of_string < SIZE_OF_BUFFER-1){ 
            data_about_line.number_of_line++;
            data_about_line.number_of_col = 0;
            }else{
                data_about_line.number_of_col += SIZE_OF_BUFFER-1;
            }
    }
    }
    if(dir != NULL){
    while( (entry=readdir(dir)) )
    {
        if(strcmp(entry->d_name, search_text) == 0){
        char type[5];
        if(entry->d_type == DIR_ID) strcpy(type,"dir");
        if(entry->d_type == FILE_ID) strcpy(type,"file");
        printf("found %s: %s\n",type, entry->d_name);
        count_of_found++;
        }
    }
    }
    printf("total of found elements: %d\n",count_of_found);
    fclose(file);
    closedir(dir);
    return SUCCES_EXIT;
}