#include <stdio.h>
#include <string.h>
#define SIZE_OF_BUFFER 100

void search_in_buffer(char* buffer,int len_of_buffer, char* search_text, int len_of_search, int number_of_line){
    int found = 0;
    for(int i = 0; i<len_of_buffer; i++){
        if(buffer[i] == search_text[0]){
            for(int j = 0; j<len_of_search; j++){
                if(buffer[i+j] != search_text[j]) break;

                found++;

                if(found == len_of_search){
                    printf("find at %d line\n",number_of_line);
                    found = 0;
                }
            }
        }
        found = 0;
    }

}

int main(int argc, char* argv[]){
    FILE* file;
    int number_of_line = 1;
    int len_of_buffer;
    char line_of_file[SIZE_OF_BUFFER];
    char search_text[1] = "0";



    
    file = fopen("test.txt","r");
    if (file != NULL)
    {
        while (fgets(line_of_file,SIZE_OF_BUFFER,file))
        {
            len_of_buffer = strlen(line_of_file);
            search_in_buffer(line_of_file,len_of_buffer, search_text, 1, number_of_line);
            if(len_of_buffer < SIZE_OF_BUFFER) number_of_line++;
        }
        
    }
    

    if(argc > 1){
        printf("argument : %s\n",argv[1]);
    }
    return 0;
}