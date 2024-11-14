#include "mylib.h"

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