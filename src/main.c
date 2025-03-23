#include "../inc/functions.h"

int main(int argc, char* argv[]){
    int count_of_found = 0;
    Data_from_user data_from_user ={argc,argv};

    if(check_numbers_of_arguments(data_from_user.argc)){
        return ERROR_EXIT;
    }

    FILE* file = fopen(argv[1],"r");
    DIR* dir = opendir(argv[1]);

    if(check_if_path_exits(data_from_user)){
        return ERROR_EXIT;
    }

    if(file != NULL){
        count_of_found = path_is_a_file(data_from_user,file);
        fclose(file);
    }

    if(dir != NULL){
        count_of_found = path_is_a_dir(data_from_user,dir);
        closedir(dir);
    }
    printf("total of found elements: %d\n",count_of_found);
    return SUCCES_EXIT;
}