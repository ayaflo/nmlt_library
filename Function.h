
#ifndef FUNCTION_H
#define FUNCTION_H
void setColSizeConsole();
void clearConsole();
void print_logo();

bool compare_char_array(const char array1[], const char array2[]);
int charArrayToNumber(const char str[]);
void intToCharArray(int number, char result[]);
int daysInMonth(int month, int year);
void parseDate(const char date[], int& day, int& month, int& year);
int totalDays(int day, int month, int year);
int check(char arr1[], char arr2[]) ;
#endif //FUNCTION_H
