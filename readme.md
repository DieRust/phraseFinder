# Lab 2 report from Pros subject
## Rafał Lesiak index's number 331254

In this project i must to do a program to find phrase in given path to file.\
A phraze and path must be given in call arguments. The program's outputs will be the number of line and number of column in this file.

To do this i made my own library which in I predefine my structs and my function.\
Structs:
* **Data_about_line** hold number of curent line and number of culumn.
* **string_data** hold number of size chars table and chars table.

Function:
* **search_in_buffer()** it search in buffer a given phrase, evrytime if they did it, it will write in terminal current number of line and column.

In the main function at first I check if user give the good number of arguments, next i check if the given path to file exits. If both condition are true the program in while loop will take the chars from a file until the end of file. At the end the prgram will return total number of find elements.

To tests i use free template of .txt and .csv file from https://www.online-convert.com. If i gave wrong number of arguments then program exit with error, the same thing is going if the path does not exit. In my tests I use command: "./lab test.txt "TXT" " and "./lab test.csv "$" ", and evrything work as expected. 

