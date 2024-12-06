#ifndef TRANSACTION_H
#define TRANSACTION_H


void add_transaction(char transaction[100][6][100],char idOfReader[],char borrow_date[],char return_date[],char actual_return_date[],char ISBNs[],char fine_amount[]);
void edit_transaction(char find_idOfReader[],char transaction[100][6][100],char idOfReader[],char borrow_date[],char return_date[],char actual_return_date[],char ISBNs[],char fine_amount[]);
int search_id_transaction(const char idOfReader[],const char transaction[100][6][100]);
void return_transaction(char find_idOfReader[],char book[100][8][100],char transaction[100][6][100],char actual_return_date[],char ISBNs[]);
void display_transaction(char transaction[100][6][100]);
void display_all_transaction(char transaction[100][6][100]);
int total_borrow_book(char transaction[100][6][100]);
int total_late_returned_book(char transaction[100][6][100]);

void case1_borrow_transaction(char data_transaction[100][6][100]);
void case2_return_transaction(char data_transaction[100][6][100],char data_book[100][8][100]);
void case3_view_transaction(char data_transaction[100][6][100]);

void case5_statistics(char data_transaction[100][6][100]);
void case6_statistics(char data_transaction[100][6][100]);
#endif //TRANSACTION_H
