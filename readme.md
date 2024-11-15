# Lab 2 report from Pros subject
## Rafał Lesiak index's number 331254

In this project i must to do a program to find phrase in given path to file.\
A phraze and path must be given in call arguments. The program's outputs will be the number of line and number of column in this file.

To do this i made my own library which in I predefine my structs and my functions.\
Structs:
* **Data_about_line** hold number of curent line and number of culumn.
* **String_data** hold number of size chars table and chars table.
* **Data_from_user** hold number of given arguments and pointer to char table

Functions:
* **check_numbers_of_arguments()** check if number of given arguments is equal to 3
* **check_if_path_exits()** check if given path exits
* **path_is_a_file()** do logic for file type path
* **search_in_buffer()** it searches in buffer for a given phrase, everytime if program finds it, it will write in terminal current number of line and column.
* **path_is_a_dir** do logic for directory type path

In the main function at first I check if user give the good number of arguments, next i check if the given path to file exits. If both condition are true the program in while loop will take the chars from a file until the end of file. Or if path is directory program search in all directory if given phraze is in this dir. At the end the prgram will return total number of find elements.

In addiction program also can take dir location as a path to look for given phrase.

To tests i use free template of .txt and .csv file from https://www.online-convert.com. If i gave wrong number of arguments then program exit with error, the same thing is going if the path does not exit. In my tests I use command: "./lab test/test.txt "TXT" ", "./lab test/test.csv "$" ","./lab "test" "test.txt", and evrything work as expected. 

