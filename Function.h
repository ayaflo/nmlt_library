
#ifndef FUNCTION_H
#define FUNCTION_H
void setColSizeConsole();
void clearConsole();
void print_logo();
void reset_char_array(char array[],int size);
bool compare_char_array(const char array1[], const char array2[]);
int charArrayToNumber(const char str[]);
void set_expiry_date(char reader[100][9][100],int i);
void formatDate(int day, int month, int year, char result[]);
void intToCharArray(int number, char result[]);
int daysInMonth(int month, int year);
void parseDate(const char date[], int& day, int& month, int& year);
int totalDays(int day, int month, int year);
int check(char arr1[], char arr2[]) ;
#endif //FUNCTION_H
