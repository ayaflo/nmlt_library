#include <iostream>
void setColSizeConsole() {
#ifdef _WIN32
	// Windows-specific command using 'mode'
	char command[] = "mode con: cols=300";
	//char command[]="mode 650";
	system(command);
#elif __linux__ || __APPLE__
	// Linux/Mac-specific command using 'stty'
	char command[] = "stty cols 300";
	system(command);
	//#else
	//std::cerr << "Console resizing not supported on this operating system." << std::endl;
#endif
}

void clearConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
void print_logo() {
	std::cout<<" _   _  ____ __  __ _   _ ____    _     _ _                          \n"
			 <<"| | | |/ ___|  \\/  | | | / ___|  | |   (_) |__  _ __ __ _ _ __ _   _ \n"
			 <<"| |_| | |   | |\\/| | | | \\___ \\  | |   | | '_ \\| '__/ _` | '__| | | |\n"
			 <<"|  _  | |___| |  | | |_| |___) | | |___| | |_) | | | (_| | |  | |_| |\n"
			 <<"|_| |_|\\____|_|  |_|\\___/|____/  |_____|_|_.__/|_|  \\__,_|_|   \\__, |\n"
			 <<"                                                               |___/ \n";
}
void reset_char_array(char array[],int size) {
	for (int i = 0; i < size; ++i) {
		array[i] = '\0';
	}
}
bool compare_char_array(const char array1[], const char array2[]) {
	int i = 0;
	// Compare characters one by one until the null terminator
	while (array1[i] != '\0' && array2[i] != '\0') {
		if (array1[i] != array2[i]) {
			return false; // Mismatch found
		}

		i++;
	}
	return (array1[i] == '\0' && array2[i] == '\0');
}
int charArrayToNumber(const char str[]) {
	int number = 0;
	int i = 0;
	// Process each character
	while (str[i] != '\0') {
		number = number * 10 + (str[i] - '0'); // Convert char to digit and accumulate
		i++;
	}
	return number;
}
void intToCharArray(int number, char result[]) {
	int index = 0;
	int temp = number;
	// Count the number of digits
	do {
		index++;
		temp /= 10;
	} while (temp > 0);
	// Handle the special case of 0
	if (index == 0) {
		result[0] = '0';
		result[1] = '\0';
		return;
	}
	result[index] = '\0';

	// Fill the array with digits in reverse order
	while (number > 0) {
		result[--index] = (number % 10) + '0'; // Convert digit to character
		number /= 10;
	}
}

//formatDate to dd/mm/yyyy
void formatDate(int day, int month, int year, char result[]) {
	int temp;
	int index = 0;
	if (day >= 10) {
		temp = day / 10;
		result[index++] = '0' + temp;
		day -= temp * 10;
	}
	result[index++] = '0' + day;
	result[index++] = '/';
	if (month >= 10) {
		temp = month / 10;
		result[index++] = '0' + temp;
		month -= temp * 10;
	}
	result[index++] = '0' + month;
	result[index++] = '/';
	temp = year;
	int divisor = 1000;
	while (divisor > 0) {
		int digit = temp / divisor;
		result[index++] = '0' + digit;
		temp %= divisor;
		divisor /= 10;
	}
	result[index] = '\0';
}

// Helper function to count the number of days in a month
int daysInMonth(int month, int year) {
	switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))? 29: 28;
		default:
			return 0;  // Invalid month
	}
}

// Helper function to parse a date in "dd/mm/yyyy" format
void parseDate(const char date[], int& day, int& month, int& year) {
	day = 0;
	month = 0;
	year = 0;
	int i = 0;
	// Parse day
	while (date[i] != '/' && date[i] != '\0') {
		day = day * 10 + (date[i] - '0');
		++i;
	}
	++i;
	// Parse month
	while (date[i] != '/' && date[i] != '\0') {
		month = month * 10 + (date[i] - '0');
		++i;
	}
	++i;
	// Parse year
	while (date[i] != '\0') {
		year = year * 10 + (date[i] - '0');
		++i;
	}
}

// The function to calculate the total number of days from 01/01/0001 to the given date
int totalDays(int day, int month, int year) {
	// Days from complete years
	int total = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	// Days from complete months in the current year
	for (int m = 1; m < month; ++m) {
		total += daysInMonth(m, year);
	}
	total += day;
	return total;
}

// Function to calculate the gap between two dates
int check(char arr1[], char arr2[]) {
	int day1, month1, year1, day2, month2, year2;
	// Parse the dates
	parseDate(arr1, day1, month1, year1);
	parseDate(arr2, day2, month2, year2);
	// Convert each date to the total number of days
	int total1 = totalDays(day1, month1, year1);
	int total2 = totalDays(day2, month2, year2);
	// Return the absolute difference
	return (total1>total2)?(total1 - total2):(total2-total1);
}
void set_expiry_date(char reader[100][9][100],int i) {
	int day,month,year;
	parseDate(reader[i][7],day,month,year);
	year+=4;
	char result[100];
	formatDate(day,month,year,reader[i][8]);
}