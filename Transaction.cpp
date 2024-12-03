#define null_value '@'
#include "Transaction.h"
#include <iomanip>
#include <iostream>
#include "Function.h"
#include "Book.h"
void add_transaction(char transaction[100][6][100],char idOfReader[],char borrow_date[],char return_date[],char actual_return_date[],char ISBNs[],char fine_amount[]) {
	unsigned int i=0,location=-1;
	do {
		location++;
		if (transaction[location][0][0]=='\0') {
			//edit transaction's information
			i=0;
			while (idOfReader[i]!='\0') {
				transaction[location][0][i]=idOfReader[i];
				i++;
			}
			i=0;
			while (borrow_date[i]!='\0') {
				transaction[location][1][i]=borrow_date[i];
				i++;
			}
			i=0;
			while (return_date[i]!='\0') {
				transaction[location][2][i]=return_date[i];
				i++;
			}
			i=0;
			while (actual_return_date[i]!='\0') {
				transaction[location][3][i]=actual_return_date[i];
				i++;
			}
			i=0;
			while (ISBNs[i]!='\0') {
				transaction[location][4][i]=ISBNs[i];
				i++;
			}
			i=0;
			while (fine_amount[i]!='\0' ) {
				transaction[location][5][i]=fine_amount[i];
				i++;
			}
			break;
		}

	}while (transaction[location][0][0]!='\0' && location<99);
	std::cout << "Add transaction successfully!\n";
}
void edit_transaction(char find_idOfReader[],char transaction[100][6][100],char idOfReader[],char borrow_date[],char return_date[],char actual_return_date[],char ISBNs[],char fine_amount[]) {
	unsigned int i=0,location=0;
	//find the reader who need to be edited
	bool check=false;
	while (transaction[location][0][0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; transaction[location][0][j] != '\0' || find_idOfReader[j] != '\0'; ++j) {
			if (transaction[location][0][j] != find_idOfReader[j]) {
				check=false;
				break;
			}
		}
		if (check==true) {
			//output infor about the transaction
			break;
		}
		location++;
	}
	if (transaction[location][0][0]=='\0')
		return;
	//edit transaction's information
	while (idOfReader[i]!='\0') {
		transaction[location][0][i]=idOfReader[i];
		i++;
	}
	transaction[location][0][i]='\0';
	i=0;
	while (borrow_date[i]!='\0') {
		transaction[location][1][i]=borrow_date[i];
		i++;
	}
	transaction[location][1][i]='\0';
	i=0;
	while (return_date[i]!='\0') {
		transaction[location][2][i]=return_date[i];
		i++;
	}
	transaction[location][2][i]='\0';
	i=0;
	while (actual_return_date[i]!='\0') {
		transaction[location][3][i]=actual_return_date[i];
		i++;
	}
	transaction[location][3][i]='\0';
	i=0;
	while (ISBNs[i]!='\0') {
		transaction[location][4][i]=ISBNs[i];
		i++;
	}
	transaction[location][4][i]='\0';
	i=0;
	while (fine_amount[i]!='\0') {
		transaction[location][5][i]=fine_amount[i];
		i++;
	}
	transaction[location][5][i]='\0';
}
void return_transaction(char find_idOfReader[],char book[100][8][100],char transaction[100][6][100],char actual_return_date[],char ISBNs[]) {
	int i=search_id_transaction(find_idOfReader,transaction); //get the position of the reader in the transaction list, who borrowing book
	if (i==-1) {
		std::cout<<"Error: Cannot find id of reader"<<std::endl;
		return;
	}
	char ISBNs_borrow[100][100],ISBNs_return[100][100];
	//split transaction[i][4] (1d char array) into ISBNs_borrow (2d char array) which contains all ISBN been borrowed
	int count=0;
	int row = 0, col = 0;
	for (int j = 0; transaction[i][4][j] != '\0'; j++) {
		if (transaction[i][4][j] == ' ') {
			ISBNs_borrow[row][col] = '\0';
			row++;
			col = 0;
		} else {
			ISBNs_borrow[row][col] = transaction[i][4][j];
			col++;
		}
	}
	ISBNs_borrow[row][col] = '\0';
	count = row + 1;//count the number of ISBN
	//split ISBNs (1d char array) into ISBNs_return (2d char array) which contains all ISBN have just returned
	row = 0; col = 0;
	for (int j = 0; ISBNs[j] != '\0'; j++) {
		if (ISBNs[j] == ' ') {
			ISBNs_return[row][col] = '\0';
			row++;
			col = 0;
		} else {
			ISBNs_return[row][col] = ISBNs[j];
			col++;
		}
	}
	ISBNs_return[row][col] = '\0';
	//
	for (int j=0;j<count;j++) {
		int k=0;
		while (ISBNs_return[k][0]!='\0') {
			if (compare_char_array(ISBNs_return[k],ISBNs_borrow[j])) {
				//do something
				ISBNs_borrow[j][0]='\n'; //if the book with ISBN has returned, set'\n' into the ISBN in ISBNs_borrow for easily detecting
				break;
			}
			k++;
		}
	}
	int total_fine_amount=charArrayToNumber(transaction[i][5]),price,ISBN_not_returned=1;
	for (int j=0;j<count;j++) {
		if (ISBNs_borrow[j][0] != '\n') {
			int k=0;
			while (book[k][0][0]!='\0') {
				if (compare_char_array(book[k][0],ISBNs_borrow[j])) {
					//do something
					ISBN_not_returned++;
					price=charArrayToNumber(book[k][6]);
					total_fine_amount+=(price*2);
					break;
				}
				k++;
			}
		}
	}
	int checkTwoDays=check(transaction[i][1],actual_return_date);
	if (checkTwoDays>7)
		total_fine_amount+=(checkTwoDays-7)*5000*ISBN_not_returned;

	char update_ISBNs[100];
	int pos_update_ISBN=0;

		for (int j=0;j<count;j++) {
			if (ISBNs_borrow[j][0] != '\n' && ISBNs_borrow[j][0]!='\0'){
				int m=0;
				while (ISBNs_borrow[j][m]!='\0') {
					update_ISBNs[pos_update_ISBN]=ISBNs_borrow[j][m];
					m++;
					pos_update_ISBN++;
				}
				if (ISBNs_borrow[j+1][0]!='\0') {
					update_ISBNs[pos_update_ISBN]=' ';
					pos_update_ISBN++;
				}
			}
			//
		}
	update_ISBNs[pos_update_ISBN]='\0';
	if (update_ISBNs[0]=='\0') {
		update_ISBNs[0]=null_value;
	}

	char total_fine_amount_chars[100];
	intToCharArray(total_fine_amount,total_fine_amount_chars);
	if (total_fine_amount_chars[0]=='\0') {
		total_fine_amount_chars[0]='0';
	}
	edit_transaction(find_idOfReader,transaction,transaction[i][0],transaction[i][1],transaction[i][2],actual_return_date,update_ISBNs,total_fine_amount_chars);
	std::cout << "Return book succesfully!\n";
}

int search_id_transaction(const char idOfReader[],const char transaction[100][6][100]) {
	bool check=false;
	int i=0;
	while (transaction[i][0][0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; transaction[i][0][j] != '\0' || idOfReader[j] != '\0'; ++j) {
			if (transaction[i][0][j] != idOfReader[j]) {
				check=false;
				break;
			}
		}
		if (check==true) {
			//output infor about the reader
			return i;
		}
		i++;
	}
	return -1;
}
void display_transaction(char transaction[6][100]) {
	std::cout<<std::setw(15)<<transaction[0];
	std::cout<<std::setw(40)<<transaction[1];
	std::cout<<std::setw(40)<<transaction[2];
	if (transaction[3][0]==null_value) {
		std::cout<<std::setw(40)<<"(empty)";
	}
	else
		std::cout<<std::setw(40)<<transaction[3];
	if (transaction[4][0]==null_value) {
		std::cout<<std::setw(60)<<"(empty)";
	}
	else
		std::cout<<std::setw(60)<<transaction[4];
	std::cout<<std::setw(15)<<transaction[5];
	std::cout<<std::endl;
}
void display_all_transaction(char transaction[100][6][100]) {

	std::cout<<std::left<<std::setw(15)<<"ID of Reader"
	<<std::setw(40)<<"Borrow Date"
	<<std::setw(40)<<"Return Date"
	<<std::setw(40)<<"Actual Return Date"
	<<std::setw(60)<<"Pending ISBNs"
	<<std::setw(15)<<"Fine amount"<<std::endl;
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	int i=0;
	while (transaction[i][0][0]!='\0') {
		display_transaction(transaction[i]);
		i++;
	}
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;

}
int total_borrow_book(char transaction[100][6][100]) {
	int i=0,count=0,j=0;

	while (transaction[i][0][0]!='\0') {
		if (transaction[i][4][0]!=null_value) {
			j=0;
			while (transaction[i][4][j]!='\0') {
				if (transaction[i][4][j]==' ')
					count++;
				j++;
			}
			count++;
		}
		i++;
	}
	return count;
}
int total_late_returned_book(char transaction[100][6][100]) {
	int i=0,count=0;
	while (transaction[i][0][0]!='\0') {
		if (transaction[i][3][0]!=null_value) {
			if (check(transaction[i][1],transaction[i][3])>7)
				count++;
		}
		i++;
	}
	return count;
}

void case1_borrow_transaction(char data_transaction[100][6][100]) {
	clearConsole();
	display_all_transaction(data_transaction);
	std::cout << "Borrow book...\n";
	char idOfReader[100],borrow_date[100],return_date[100],actual_return_date[100],ISBNs[100],fine_amount[100];
	std::cin.ignore();
	std::cout<<"Enter id of reader: ";
	std::cin.getline(idOfReader,100);
	std::cout<<"Enter Borrow date: ";
	std::cin.getline(borrow_date,100);
	std::cout<<"Enter Return date: ";
	std::cin.getline(return_date,100);
	std::cout<<"Enter list ISBNs of borrow book: ";
	std::cin.getline(ISBNs,100);
	actual_return_date[0]='@';
	fine_amount[0]='0';
	fine_amount[1]='\0';
	add_transaction(data_transaction,idOfReader,borrow_date,return_date,actual_return_date,ISBNs,fine_amount);

	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case2_return_transaction(char data_transaction[100][6][100],char data_book[100][8][100]) {
	clearConsole();
	display_all_transaction(data_transaction);
	std::cout << "Return book...\n"
		  <<"Enter id of reader: ";
	char find_idOfReader[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(find_idOfReader,100,'\n');
	char ISBNs[100],actual_return_date[100];
	std::cout<<"Enter ISBNs of return book: ";
	std::cin.getline(ISBNs,100);
	std::cout<<"Enter Actual return date: ";
	std::cin.getline(actual_return_date,100);
	return_transaction(find_idOfReader,data_book,data_transaction,actual_return_date,ISBNs);
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case5_statistics(char data_transaction[100][6][100]) {
	clearConsole();
	display_all_transaction(data_transaction);
	std::cout << "Statistics on borrowed books: "<<total_borrow_book(data_transaction)<<std::endl;
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case6_statistics(char data_transaction[100][6][100]) {
	clearConsole();
	display_all_transaction(data_transaction);
	std::cout << "Statistics on overdue readers: "<<total_late_returned_book(data_transaction)<<std::endl;
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
