
#ifndef READER_H
#define READER_H


void display_all_reader(const char reader[100][9][100]);
void display_reader(const char reader[9][100]);
void edit_reader(char find_id[],char reader[100][9][100],char id[],char name[],char cmnd[],char birthdate[],char gender[],char email[],char address[],char issue_date[],char expiry_date[]);
void add_reader(char reader[100][9][100],char id[],char name[],char cmnd[],char birthdate[],char gender[],char email[],char address[],char issue_date[],char expiry_date[]);
void remove_reader(char find_id[],char reader[100][9][100]);
int search_cmnd_reader(const char cmnd[],const char reader[100][9][100]);
int search_name_reader(const char name[],const char reader[100][9][100]);

int total_reader(const char reader[100][9][100]);
int total_reader_gender(const char gender[],const char reader[100][9][100]);
void set_expiry_date(char reader[100][9][100]);

void case1_view_all_readers(const char data_reader[100][9][100]);
void case2_add_reader(char data_reader[100][9][100]);
void case3_edit_reader(char data_reader[100][9][100]);
void case4_delete_reader(char data_reader[100][9][100]);
void case5_search_reader(char data_reader[100][9][100]);
void case6_search_reader(char data_reader[100][9][100]);

void case3_statistic(char data_reader[100][9][100]);
void case4_statistic(char data_reader[100][9][100]);
#endif //READER_H
