#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "Function.h"

void add_transaction(data_transaction transaction[],char idOfReader[],char borrow_date[],char return_date[],char actual_return_date[],char ISBNs[],char fine_amount[]);
void edit_transaction(char find_idOfReader[],data_transaction transaction[],char idOfReader[],char borrow_date[],char return_date[],char actual_return_date[],char ISBNs[],char fine_amount[]);
int search_id_transaction(const char idOfReader[],const data_transaction transaction[]);
void return_transaction(char find_idOfReader[],data_book book[],data_transaction transaction[],char actual_return_date[],char ISBNs[]);
void display_transaction(data_transaction transaction[]);
void display_all_transaction(data_transaction transaction[]);
int total_borrow_book(data_transaction transaction[]);
int total_late_returned_book(data_transaction transaction[]);

void case1_borrow_transaction(data_transaction transaction[]);
void case2_return_transaction(data_transaction transaction[],data_book book[]);
void case3_view_transaction(data_transaction transaction[]);

void case5_statistics(data_transaction transaction[]);
void case6_statistics(data_transaction transaction[]);
#endif //TRANSACTION_H
