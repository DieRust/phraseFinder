#include <stdio.h>
#include <string.h>
#define SIZE_OF_BUFFER 100
#define ERROR_EXIT -1
#define SUCCES_EXIT 0

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


void search_in_buffer(string_data buffer_of_file, char* search_text, int len_of_search, 
    Data_about_line data_about_line, int* count_of_found){
    int found = 0;
    for(int i = 0; i<buffer_of_file.len_of_string; i++){
        if(buffer_of_file.string[i] == search_text[0]){
            for(int j = 0; j<len_of_search; j++){
                if(buffer_of_file.string[i+j] != search_text[j]) break;

                found++;

                if(found == len_of_search){
                    printf("\"%s\" find at %d line in %d column\n",search_text,data_about_line.number_of_line,
                    data_about_line.number_of_col+i);
                    *count_of_found += 1;
                    found = 0;
                }
            }
        }
        found = 0;
    }

}

int main(int argc, char* argv[]){
    FILE* file;
    int count_of_found = 0;
    string_data buffer_of_file;
    Data_about_line data_about_line = {0,0}; 


    if(argc != 3){
        printf("wrong number of input\nyou should use this template: ./lab path search_txt\n");
        return ERROR_EXIT;
    }

    file = fopen(argv[1],"r");
    
    if (file == NULL){
        printf("you use wrong path\n");
        return ERROR_EXIT;
    }

    int len_of_search_text = strlen(argv[2]);
    char search_text[len_of_search_text];

    strcpy(search_text,argv[2]);

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
    printf("total of found elements: %d\n",count_of_found);
    
    return SUCCES_EXIT;
}