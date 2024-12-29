#define null_value '@'
#include "Transaction.h"
#include <iomanip>
#include <iostream>
#include "Function.h"
void add_transaction(data_transaction transaction[],char idOfReader[],char borrow_date[],char return_date[],char actual_return_date[],char ISBNs[],char fine_amount[]) {
	unsigned int i=0,location=-1;
	do {
		location++;
		if (transaction[location].idOfReader[0]=='\0') {
			//edit transaction's information
			i=0;
			while (idOfReader[i]!='\0') {
				transaction[location].idOfReader[i]=idOfReader[i];
				i++;
			}
			i=0;
			while (borrow_date[i]!='\0') {
				transaction[location].borrow_date[i]=borrow_date[i];
				i++;
			}
			i=0;
			while (return_date[i]!='\0') {
				transaction[location].return_date[i]=return_date[i];
				i++;
			}
			i=0;
			while (actual_return_date[i]!='\0') {
				transaction[location].actual_return_date[i]=actual_return_date[i];
				i++;
			}
			i=0;
			while (ISBNs[i]!='\0') {
				transaction[location].ISBNs[i]=ISBNs[i];
				i++;
			}
			i=0;
			while (fine_amount[i]!='\0' ) {
				transaction[location].fine_amount[i]=fine_amount[i];
				i++;
			}
			break;
		}

	}while (transaction[location].idOfReader[0]!='\0' && location<99);
	std::cout << "Add transaction successfully!\n";
}
void edit_transaction(char find_idOfReader[],data_transaction transaction[],char idOfReader[],char borrow_date[],char return_date[],char actual_return_date[],char ISBNs[],char fine_amount[]) {
	unsigned int i=0,location=0;
	//find the reader who need to be edited
	bool check=false;
	while (transaction[location].idOfReader[0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; transaction[location].idOfReader[j] != '\0' || find_idOfReader[j] != '\0'; ++j) {
			if (transaction[location].idOfReader[j] != find_idOfReader[j]) {
				check=false;
				break;
			}
		}
		if (check==true) {
			break;
		}
		location++;
	}
	if (transaction[location].idOfReader[0]=='\0')
		return;
	//edit transaction's information
	while (idOfReader[i]!='\0') {
		transaction[location].idOfReader[i]=idOfReader[i];
		i++;
	}
	transaction[location].idOfReader[i]='\0';
	i=0;
	while (borrow_date[i]!='\0') {
		transaction[location].borrow_date[i]=borrow_date[i];
		i++;
	}
	transaction[location].borrow_date[i]='\0';
	i=0;
	while (return_date[i]!='\0') {
		transaction[location].return_date[i]=return_date[i];
		i++;
	}
	transaction[location].return_date[i]='\0';
	i=0;
	while (actual_return_date[i]!='\0') {
		transaction[location].actual_return_date[i]=actual_return_date[i];
		i++;
	}
	transaction[location].actual_return_date[i]='\0';
	i=0;
	while (ISBNs[i]!='\0') {
		transaction[location].ISBNs[i]=ISBNs[i];
		i++;
	}
	transaction[location].ISBNs[i]='\0';
	i=0;
	while (fine_amount[i]!='\0') {
		transaction[location].fine_amount[i]=fine_amount[i];
		i++;
	}
	transaction[location].fine_amount[i]='\0';
}
void return_transaction(char find_idOfReader[],data_book book[],data_transaction transaction[],char actual_return_date[],char ISBNs[]) {
	int i=search_id_transaction(find_idOfReader,transaction); //get the position of the reader in the transaction list, who borrowing book
	int count_ISBNs_borrow,count_ISBNs_return;
	if (i==-1) {
		std::cout<<"Error: Cannot find id of reader"<<std::endl;
		return;
	}
	char ISBNs_borrow[100][100],ISBNs_return[100][100];

	//split transaction[i].ISBNs (1d char array) into ISBNs_borrow (2d char array) which contains all ISBN have been borrowed
	int count=0;
	int row = 0, col = 0;
	for (int j = 0; transaction[i].ISBNs[j] != '\0'; j++) {
		if (transaction[i].ISBNs[j] == ' ') {
			ISBNs_borrow[row][col] = '\0';
			row++;
			col = 0;
		} else {
			ISBNs_borrow[row][col] = transaction[i].ISBNs[j];
			col++;
		}
	}
	ISBNs_borrow[row][col] = '\0';
	count_ISBNs_borrow=row+1;
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
	count_ISBNs_return=row+1;
	ISBNs_return[row][col] = '\0';
	//
	for (int j=0;j<count;j++) {
		int k=0;
		while (ISBNs_return[k][0]!='\0') {
			if (compare_char_array(ISBNs_return[k],ISBNs_borrow[j])) {
				//do something
				ISBNs_borrow[j][0]='\0'; //if the book with ISBN has returned, set'\0' into the ISBN in ISBNs_borrow for easily detecting
				//reset_char_array(ISBNs_borrow[j],100);
				break;
			}
			k++;
		}
	}

	int total_fine_amount=charArrayToNumber(transaction[i].fine_amount),price;
	int checkTwoDays=check(transaction[i].borrow_date,actual_return_date);
	for (int j=0;j<count;j++) {
		if (ISBNs_borrow[j][0] != '\0') {
			int k=0;
			while (book[k].ISBN[0]!='\0') {
				if (compare_char_array(book[k].ISBN,ISBNs_borrow[j])) {
					price=charArrayToNumber(book[k].price);
					total_fine_amount+=(price*2);
					break;
				}
				k++;
			}
		}
	}
	if (checkTwoDays>7)
		total_fine_amount+=(checkTwoDays-7)*5000*count;

	char update_ISBNs[100];
	int pos_update_ISBN=0;
		for (int j=0;j<count;j++) {
			if (ISBNs_borrow[j][0] != '\0'){
				int m=0;
				if (pos_update_ISBN!=0) {
					update_ISBNs[pos_update_ISBN]=' ';
					pos_update_ISBN++;
				}
				while (ISBNs_borrow[j][m]!='\0') {
					update_ISBNs[pos_update_ISBN]=ISBNs_borrow[j][m];
					m++;
					pos_update_ISBN++;
				}

			}
			//
		}
	update_ISBNs[pos_update_ISBN]='\0';
	if (update_ISBNs[0]=='\0') {
		update_ISBNs[0]=null_value;
		update_ISBNs[1]='\0';
	}

	char total_fine_amount_chars[100];
	intToCharArray(total_fine_amount,total_fine_amount_chars);
	if (total_fine_amount_chars[0]=='\0') {
		total_fine_amount_chars[0]='0';
	}
	edit_transaction(find_idOfReader,transaction,transaction[i].idOfReader,transaction[i].borrow_date,transaction[i].return_date,actual_return_date,update_ISBNs,total_fine_amount_chars);
	std::cout << "Return book successfully!\n";
	for (int l=0;l<count_ISBNs_borrow;l++)
		reset_char_array(ISBNs_borrow[l],100);
	for (int l=0;l<count_ISBNs_return;l++)
		reset_char_array(ISBNs_return[l],100);
}

int search_id_transaction(const char idOfReader[],const data_transaction transaction[]) {
	bool check=false;
	int i=0;
	while (transaction[i].idOfReader[0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; transaction[i].idOfReader[j] != '\0' || idOfReader[j] != '\0'; ++j) {
			if (transaction[i].idOfReader[j] != idOfReader[j]) {
				check=false;
				break;
			}
		}
		if (check==true) {
			return i;
		}
		i++;
	}
	return -1;
}
void display_transaction(data_transaction transaction) {
	std::cout<<std::setw(15)<<transaction.idOfReader;
	std::cout<<std::setw(40)<<transaction.borrow_date;
	std::cout<<std::setw(40)<<transaction.return_date;
	if (transaction.actual_return_date[0]==null_value) {
		std::cout<<std::setw(40)<<"(empty)";
	}
	else
		std::cout<<std::setw(40)<<transaction.actual_return_date;
	if (transaction.ISBNs[0]==null_value) {
		std::cout<<std::setw(60)<<"(empty)";
	}
	else
		std::cout<<std::setw(60)<<transaction.ISBNs;
	std::cout<<std::setw(15)<<transaction.fine_amount;
	std::cout<<std::endl;
}
void display_all_transaction(data_transaction transaction[]) {

	std::cout<<std::left<<std::setw(15)<<"ID of Reader"
	<<std::setw(40)<<"Borrow Date"
	<<std::setw(40)<<"Return Date"
	<<std::setw(40)<<"Actual Return Date"
	<<std::setw(60)<<"Pending ISBNs"
	<<std::setw(15)<<"Fine amount"<<std::endl;
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	int i=0;
	while (transaction[i].idOfReader[0]!='\0') {
		display_transaction(transaction[i]);
		i++;
	}
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;

}
int total_borrow_book(data_transaction transaction[]) {
	int i=0,count=0,j=0;

	while (transaction[i].idOfReader[0]!='\0') {
		if (transaction[i].ISBNs[0]!=null_value) {
			j=0;
			while (transaction[i].ISBNs[j]!='\0') {
				if (transaction[i].ISBNs[j]==' ')
					count++;
				j++;
			}
			count++;
		}
		i++;
	}
	return count;
}
int total_late_returned_book(data_transaction transaction[]) {
	int i=0,count=0;
	while (transaction[i].idOfReader[0]!='\0') {
		if (transaction[i].actual_return_date[0]!=null_value) {
			if (check(transaction[i].borrow_date,transaction[i].actual_return_date)>7)
				count++;
		}
		i++;
	}
	return count;
}

void case1_borrow_transaction(data_transaction transaction[]) {
	clearConsole();
	display_all_transaction(transaction);
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
	add_transaction(transaction,idOfReader,borrow_date,return_date,actual_return_date,ISBNs,fine_amount);

	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case2_return_transaction(data_transaction transaction[],data_book book[]) {
	clearConsole();
	display_all_transaction(transaction);
	std::cout << "Return book...\n"
		  <<"Enter id of reader: ";
	char find_idOfReader[100];
	std::cin.ignore(1,'\n');
	std::cin.getline(find_idOfReader,100,'\n');
	char ISBNs[100],actual_return_date[100];
	std::cout<<"Enter ISBNs of return book: ";
	std::cin.getline(ISBNs,100);
	std::cout<<"Enter Actual return date: ";
	std::cin.getline(actual_return_date,100);
	return_transaction(find_idOfReader,book,transaction,actual_return_date,ISBNs);
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case3_view_transaction(data_transaction transaction[]) {
	clearConsole();
	display_all_transaction(transaction);
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case5_statistics(data_transaction transaction[]) {
	clearConsole();
	display_all_transaction(transaction);
	std::cout << "Statistics on borrowed books: "<<total_borrow_book(transaction)<<std::endl;
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case6_statistics(data_transaction transaction[]) {
	clearConsole();
	display_all_transaction(transaction);
	std::cout << "Statistics on overdue readers: "<<total_late_returned_book(transaction)<<std::endl;
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
