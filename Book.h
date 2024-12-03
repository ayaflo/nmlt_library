
#ifndef BOOK_H
#define BOOK_H

void display_book(const char reader[8][100]);
void display_all_book(const char book[100][8][100]);
void add_book(char book[100][8][100],char ISBN[],char title[], char author[],char publisher[],char year[],char category[],char price[],char numberOfBooks[]);
void edit_book(char find_ISBN[],char book[100][8][100],char ISBN[],char title[], char author[],char publisher[],char year[],char category[],char price[],char numberOfBooks[]);
void remove_book(const char find_ISBN[],char book[100][8][100]);
int search_ISBN_book(const char ISBN[],const char book[100][8][100]);
int search_title_book(const char title[],const char book[100][8][100]);

int total_book(const char book[100][8][100]);
int total_book_category(const char category[],const char book[100][8][100]);

void case1_view_all_books(const char data_book[100][8][100]);
void case2_add_book(char data_book[100][8][100]);
void case3_edit_book(char data_book[100][8][100]);
void case4_delete_book(char data_book[100][8][100]);
void case5_search_book(char data_book[100][8][100]);
void case6_search_book(char data_book[100][8][100]);

void case1_statistic(char data_book[100][8][100]);
void case2_statistic(char data_book[100][8][100]);
#endif //BOOK_H
