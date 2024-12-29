
#ifndef READER_H
#define READER_H
#include "Function.h"
void display_all_reader(const data_reader reader[]);
void display_reader(const char reader[9][100]);
void edit_reader(char find_id[],data_reader reader[],char id[],char name[],char cmnd[],char birthdate[],char gender[],char email[],char address[],char issue_date[],char expiry_date[]);
void add_reader(data_reader reader[],char id[],char name[],char cmnd[],char birthdate[],char gender[],char email[],char address[],char issue_date[],char expiry_date[]);
void remove_reader(char find_id[],data_reader reader[]);
int search_cmnd_reader(const char cmnd[],const data_reader reader[]);
int search_name_reader(const char name[],const data_reader reader[]);

int total_reader(const data_reader reader[]);
int total_reader_gender(const char gender[],const data_reader reader[]);
void set_expiry_date(data_reader reader[]);

void case1_view_all_readers(const data_reader reader[]);
void case2_add_reader(data_reader reader[]);
void case3_edit_reader(data_reader reader[]);
void case4_delete_reader(data_reader reader[]);
void case5_search_reader(data_reader reader[]);
void case6_search_reader(data_reader reader[]);

void case3_statistic(data_reader reader[]);
void case4_statistic(data_reader reader[]);
#endif //READER_H
