
#ifndef BOOK_H
#define BOOK_H
#include "Function.h"
void display_book(data_book book);
void display_all_book(const data_book book[]);
void add_book(data_book book[],char ISBN[],char title[], char author[],char publisher[],char year[],char category[],char price[],char numberOfBooks[]);
void edit_book(char find_ISBN[],data_book book[],char ISBN[],char title[], char author[],char publisher[],char year[],char category[],char price[],char numberOfBooks[]);
void remove_book(const char find_ISBN[],data_book book[]);
int search_ISBN_book(const char ISBN[],const data_book book[]);
int search_title_book(const char title[],const data_book book[]);

int total_book(const data_book book[]);
int total_book_category(const char category[],const data_book book[]);

void case1_view_all_books(const data_book book[]);
void case2_add_book(data_book book[]);
void case3_edit_book(data_book book[]);
void case4_delete_book(data_book book[]);
void case5_search_book(data_book book[]);
void case6_search_book(data_book book[]);

void case1_statistic(data_book book[]);
void case2_statistic(data_book book[]);
#endif //BOOK_H
