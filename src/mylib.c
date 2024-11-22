#include "../inc/mylib.h"

int check_numbers_of_arguments(int argc){
    if(argc != 3){
        printf("wrong number of input\nyou should use this template: ./lab path search_txt\n");
        return 1;
    }
    return 0;
}

int check_if_path_exits(Data_from_user data_from_user){
    FILE* file = fopen(data_from_user.argv[1],"r");
    DIR* dir = opendir(data_from_user.argv[1]);
    if (file == NULL && dir == NULL){
        printf("you use wrong path\n");
        return 1;
    }
    return 0;
}

int path_is_a_file(Data_from_user data_from_user,FILE* file){
    String_data buffer_of_file;
    Data_about_line data_about_line={1,0};
    int count_of_find = 0;

    while (fgets(buffer_of_file.string,SIZE_OF_BUFFER,file))
    {
        buffer_of_file.len_of_string = strlen(buffer_of_file.string);
        count_of_find += search_in_buffer(buffer_of_file, data_from_user, data_about_line);

        if(buffer_of_file.len_of_string < SIZE_OF_BUFFER-1){ 
            data_about_line.number_of_line++;
            data_about_line.number_of_col = 0;
            }else{
                data_about_line.number_of_col += SIZE_OF_BUFFER-1;
            }
    }

    return count_of_find;
}


int search_in_buffer(String_data buffer_of_file, Data_from_user data_from_user, Data_about_line data_about_line){
    int found = 0;
    int number_of_found = 0;
    int len_of_search = strlen(data_from_user.argv[2]);
    char search_text[len_of_search]; 
    strcpy(search_text,data_from_user.argv[2]);
    for(int i = 0; i<buffer_of_file.len_of_string; i++){
        if(buffer_of_file.string[i] == search_text[0]){
            for(int j = 0; j<len_of_search; j++){
                if(buffer_of_file.string[i+j] != search_text[j]) break;

                found++;

                if(found == len_of_search){
                    printf("\"%s\" find at %d line in %d column\n",search_text,data_about_line.number_of_line,
                    data_about_line.number_of_col+i);
                    found = 0;
                    number_of_found++;
                }
            }
        }
        found = 0;
    }
    return number_of_found;
}

int path_is_a_dir(Data_from_user data_from_user,DIR* dir){
    int count_of_find = 0;
    char type[14]="unrecognized";
    struct dirent *entry;


    while((entry=readdir(dir)))
    {   
        strcpy(type,"unrecognized");
        if(strcmp(entry->d_name, data_from_user.argv[2]) == 0){
        if(entry->d_type == DIR_ID) strcpy(type,"dir");
        if(entry->d_type == FILE_ID) strcpy(type,"file");
        printf("found %s: %s\n",type, entry->d_name);
        count_of_find++;
        }
    }
    return count_of_find;
}