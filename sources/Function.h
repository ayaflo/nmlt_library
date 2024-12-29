
#ifndef FUNCTION_H
#define FUNCTION_H
struct data_reader {
	char id[10];
	char name[30];
	char cmnd[15];
	char birthdate[20];
	char gender[7];
	char email[40];
	char address[80];
	char issue_date[20];
	char expiry_date[20];
};
struct data_book {
	char ISBN[10];
	char title[60];
	char author[30];
	char publisher[30];
	char year[5];
	char category[10];
	char price[10];
	char numberOfBooks[4];
};
struct data_transaction {
	char idOfReader[10];
	char borrow_date[20];
	char return_date[20];
	char actual_return_date[20];
	char ISBNs[100];
	char fine_amount[10];
};
void setColSizeConsole();
void clearConsole();
void print_logo();
void reset_char_array(char array[],int size);
bool compare_char_array(const char array1[], const char array2[]);
int charArrayToNumber(const char str[]);
void set_expiry_date(data_reader &reader);
void formatDate(int day, int month, int year, char result[]);
void intToCharArray(int number, char result[]);
int daysInMonth(int month, int year);
void parseDate(const char date[], int& day, int& month, int& year);
int totalDays(int day, int month, int year);
int check(char arr1[], char arr2[]) ;
#endif //FUNCTION_H
