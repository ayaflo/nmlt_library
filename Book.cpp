#include "Book.h"
#include <iostream>
#include <iomanip>
#include "Function.h"
void edit_book(char find_ISBN[],char book[100][8][100],char ISBN[],char title[], char author[],char publisher[],char year[],char category[],char price[],char numberOfBooks[]) {
	unsigned int i=0,location=0;
	//find the reader who need to be edited
	bool check=false;
	while (book[location][0][0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; book[location][0][j] != '\0' || find_ISBN[j] != '\0'; ++j) {
			if (book[location][0][j] != find_ISBN[j]) {
				check=false;
				break;
			}
		}
		if (check==true) {
			//output infor about the reader
			break;
		}
		location++;
		if (book[location][0][0]=='\0') {
			std::cout<<"Error: Cannot find ISBN of book!\n";
			return;
		}
	}
	if (book[location][0][0]=='\0')
		return;
	//edit book's information
	while (ISBN[i]!='\0') {
		book[location][0][i]=ISBN[i];
		i++;
	}
	book[location][0][i]='\0';
	i=0;
	while (title[i]!='\0') {
		book[location][1][i]=title[i];
		i++;
	}
	book[location][1][i]='\0';
	i=0;
	while (author[i]!='\0') {
		book[location][2][i]=author[i];
		i++;
	}
	book[location][2][i]='\0';
	i=0;
	while (publisher[i]!='\0') {
		book[location][3][i]=publisher[i];
		i++;
	}
	book[location][3][i]='\0';
	i=0;
	while (year[i]!='\0') {
		book[location][4][i]=year[i];
		i++;
	}
	book[location][4][i]='\0';
	i=0;
	while (category[i]!='\0') {
		book[location][5][i]=category[i];
		i++;
	}
	book[location][5][i]='\0';
	i=0;
	while (price[i]!='\0') {
		book[location][6][i]=price[i];
		i++;
	}
	book[location][6][i]='\0';
	i=0;
	while (numberOfBooks[i]!='\0') {
		book[location][7][i]=numberOfBooks[i];
		i++;
	}
	book[location][7][i]='\0';
	std::cout << "Edit book successfully!\n";
}
void add_book(char book[100][8][100],char ISBN[],char title[], char author[],char publisher[],char year[],char category[],char price[],char numberOfBooks[]) {
	unsigned int i=0,location=-1;
	do {
		location++;
		if (book[location][0][0]=='\0') {
			//edit book's information
			i=0;
			while (ISBN[i]!='\0') {
				book[location][0][i]=ISBN[i];
				i++;
			}
			i=0;
			while (title[i]!='\0') {
				book[location][1][i]=title[i];
				i++;
			}
			i=0;
			while (author[i]!='\0') {
				book[location][2][i]=author[i];
				i++;
			}
			i=0;
			while (publisher[i]!='\0') {
				book[location][3][i]=publisher[i];
				i++;
			}
			i=0;
			while (year[i]!='\0') {
				book[location][4][i]=year[i];
				i++;
			}
			i=0;
			while (category[i]!='\0' ) {
				book[location][5][i]=category[i];
				i++;
			}
			i=0;
			while (price[i]!='\0') {
				book[location][6][i]=price[i];
				i++;
			}
			i=0;
			while (numberOfBooks[i]!='\0') {
				book[location][7][i]=numberOfBooks[i];
				i++;
			}
			break;
		}

	}while (book[location][0][0]!='\0' && location<99);
	std::cout << "Add book successfully!\n";
}
void remove_book(const char find_ISBN[],char book[100][8][100]) {
		unsigned int i=0,location=0;
	//find the reader who need to be removed
	bool check=false;
	while (book[location][0][0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; book[location][0][j] != '\0' || find_ISBN[j] != '\0'; ++j) {
			if (book[location][0][j] != find_ISBN[j]) {
				check=false;
				break;
			}
		}
		if (check==true) {
			//output infor about the book
			break;
		}
		location++;
		if (book[location][0][0]=='\0') {
			std::cout<<"Error: Cannot find ISBN of book!\n";
			return;
		}
	}
	while (book[location+1][0][0]!='\0') {
		//copy continous book into current book
		i=0;
		while (book[location+1][0][i]!='\0') {
			book[location][0][i]=book[location+1][0][i];
			i++;
		}
		book[location][0][i]='\0';
		i=0;
		while (book[location+1][1][i]!='\0') {
			book[location][1][i]=book[location+1][1][i];
			i++;
		}
		book[location][1][i]='\0';
		i=0;
		while (book[location+1][2][i]!='\0') {
			book[location][2][i]=book[location+1][2][i];
			i++;
		}
		book[location][2][i]='\0';
		i=0;
		while (book[location+1][3][i]!='\0') {
			book[location][3][i]=book[location+1][3][i];
			i++;
		}
		book[location][3][i]='\0';
		i=0;
		while (book[location+1][4][i]!='\0') {
			book[location][4][i]=book[location+1][4][i];
			i++;
		}
		book[location][4][i]='\0';
		i=0;
		while (book[location+1][5][i]!='\0') {
			book[location][5][i]=book[location+1][5][i];
			i++;
		}
		book[location][5][i]='\0';
		i=0;
		while (book[location+1][6][i]!='\0') {
			book[location][6][i]=book[location+1][6][i];
			i++;
		}
		book[location][6][i]='\0';
		i=0;
		while (book[location+1][7][i]!='\0') {
			book[location][7][i]=book[location+1][7][i];
			i++;
		}
		book[location][7][i]='\0';

		location++;
	}
	//delete the last book
	book[location][0][0]='\0';
	book[location][1][0]='\0';
	book[location][2][0]='\0';
	book[location][3][0]='\0';
	book[location][4][0]='\0';
	book[location][5][0]='\0';
	book[location][6][0]='\0';
	book[location][7][0]='\0';
	std::cout << "Delete Reader "<<find_ISBN<<" successfully!\n";
}
int search_ISBN_book(const char ISBN[],const char book[100][8][100]) {
	bool check=false;
	int i=0;
	while (book[i][1][0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; book[i][0][j] != '\0' || ISBN[j] != '\0'; ++j) {
			if (book[i][0][j] != ISBN[j]) {
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
int search_title_book(const char title[],const char book[100][8][100]) {
	bool check=false;
	int i=0;
	while (book[i][1][0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; book[i][1][j] != '\0' || title[j] != '\0'; ++j) {
			if (book[i][1][j] != title[j]) {
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
int total_book(const char book[100][8][100]) {
	int count=0,i=0;
	while (book[i][0][0]!='\0') {
		count+=charArrayToNumber(book[i][7]);
		i++;
	}
	return count;
}
int total_book_category(const char book[100][8][100],const char category[]) {
	int count=0;
	bool check=false;
	int i=0;
	while (book[i][4][0]!='\0') {
		check=true;
		// compare two char arrays to find book follow category
		for (int j = 0; book[i][4][j] != '\0' || category[j] != '\0'; ++j) {
			if (book[i][4][j] != category[j]) {
				check=false;
				break;
			}
		}
		if (check==true) {
			count++;
		}
		i++;
	}
	return count;
}
void display_book(const char book[8][100]) {
	std::cout<<std::setw(10)<<book[0];
	std::cout<<std::setw(80)<<book[1];
	std::cout<<std::setw(30)<<book[2];
	std::cout<<std::setw(30)<<book[3];
	std::cout<<std::setw(10)<<book[4];
	std::cout<<std::setw(20)<<book[5];
	std::cout<<std::setw(20)<<book[6];
	std::cout<<std::setw(15)<<book[7];
	std::cout<<std::endl;
}
void display_all_book(const char book[100][8][100]) {
	//std::cout<<book[8][0][0]<<std::endl;
	//print out the header
	std::cout<<std::left<<std::setw(10)<<"ISBN"
	<<std::setw(80)<<"Title"
	<<std::setw(30)<<"Author"
	<<std::setw(30)<<"Publisher"
	<<std::setw(10)<<"Year"
	<<std::setw(20)<<"Category"
	<<std::setw(20)<<"Price"
	<<std::setw(15)<<"Number of books"<<std::endl;
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	int i=0;
	while (book[i][0][0]!='\0') {
		display_book(book[i]);
		i++;
	}
	//std::cout<<book[0][0][0]<<std::endl;
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
}
void case1_view_all_books(const char data_book[100][8][100]) {
	clearConsole();
	std::cout << "Viewing books...\n";
	display_all_book(data_book);
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case2_add_book(char data_book[100][8][100]) {
	clearConsole();
	display_all_book(data_book);
	std::cout << "Adding book...\n";
	char ISBN[100],title[100],author[100],publisher[100],year[100],category[100],price[100],numberOfBooks[100];
	std::cin.ignore();
	std::cout<<"Enter ISBN: ";
	std::cin.getline(ISBN,100);
	std::cout<<"Enter Title: ";
	std::cin.getline(title,100);
	std::cout<<"Enter Author: ";
	std::cin.getline(author,100);
	std::cout<<"Enter Publisher: ";
	std::cin.getline(publisher,100);
	std::cout<<"Enter Year: ";
	std::cin.getline(year,100);
	std::cout<<"Enter Category: ";
	std::cin.getline(category,100);
	std::cout<<"Enter Price: ";
	std::cin.getline(price,100);
	std::cout<<"Enter Number of Books: ";
	std::cin.getline(numberOfBooks,100);
	add_book(data_book,ISBN,title,author,publisher,year,category,price,numberOfBooks);

	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case3_edit_book(char data_book[100][8][100]) {
	clearConsole();
	display_all_book(data_book);
	std::cout << "Editing Reader\n"
		  <<"Enter edited book's ISBN: ";
	char find_ISBN[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(find_ISBN,100,'\n');
	char ISBN[100],title[100],author[100],publisher[100],year[100],category[100],price[100],numberOfBooks[100];
	//std::cin.ignore();
	std::cout<<"Enter new ISBN: ";
	std::cin.getline(ISBN,100);
	std::cout<<"Enter new Title: ";
	std::cin.getline(title,100);
	std::cout<<"Enter new Author: ";
	std::cin.getline(author,100);
	std::cout<<"Enter new Publisher: ";
	std::cin.getline(publisher,100);
	std::cout<<"Enter new Year: ";
	std::cin.getline(year,100);
	std::cout<<"Enter new Category: ";
	std::cin.getline(category,100);
	std::cout<<"Enter new Price: ";
	std::cin.getline(price,100);
	std::cout<<"Enter new Number of Books: ";
	std::cin.getline(numberOfBooks,100);

	edit_book(find_ISBN,data_book,ISBN,title,author,publisher,year,category,price,numberOfBooks);

	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case4_delete_book(char data_book[100][8][100]) {
	clearConsole();
	display_all_book(data_book);
	std::cout << "Deleting book\n"
			  <<"Enter deleted book's ISBN: ";
	char find_ISBN[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(find_ISBN,100,'\n');
	remove_book(find_ISBN,data_book);
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case5_search_book(char data_book[100][8][100]) {
	clearConsole();
	display_all_book(data_book);
	std::cout << "Searching book by book's ISBN...\n";
	std::cout<<"Enter ISBN of book: ";
	char find_ISBN[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(find_ISBN,100,'\n');
	int location=search_ISBN_book(find_ISBN,data_book);
	if(location==-1)
		std::cout<<"No such book\n";
	else {
		std::cout<<std::endl;
		std::cout<<std::left<<std::setw(10)<<"ISBN"
				 <<std::setw(80)<<"Title"
				 <<std::setw(30)<<"Author"
				 <<std::setw(30)<<"Publisher"
				 <<std::setw(10)<<"Year"
				 <<std::setw(20)<<"Category"
				 <<std::setw(20)<<"Price"
				 <<std::setw(15)<<"Number of books"<<std::endl;
		std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
		display_book(data_book[location]);
		std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	}
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case6_search_book(char data_book[100][8][100]) {
	clearConsole();
	display_all_book(data_book);
	std::cout << "Searching book by book's title...\n";
	std::cout<<"Enter book's title: ";
	char find_title[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(find_title,100,'\n');
	int location=search_title_book(find_title,data_book);
	if(location==-1)
		std::cout<<"No such book\n";
	else {
		std::cout<<std::endl;
		std::cout<<std::left<<std::setw(10)<<"ISBN"
				 <<std::setw(80)<<"Title"
				 <<std::setw(30)<<"Author"
				 <<std::setw(30)<<"Publisher"
				 <<std::setw(10)<<"Year"
				 <<std::setw(20)<<"Category"
				 <<std::setw(20)<<"Price"
				 <<std::setw(15)<<"Number of books"<<std::endl;
		std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
		display_book(data_book[location]);
		std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	}
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}

void case1_statistic(char data_book[100][8][100]) {
	clearConsole();
	display_all_book(data_book);
	std::cout<<"Statistic:\n";
	std::cout<<"Statistics on the number of books: "<<total_book(data_book)<<std::endl;
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case2_statistic(char data_book[100][8][100]) {
	clearConsole();
	display_all_book(data_book);
	std::cout << "Statistics on books by category...\n";
	std::cout<<"Enter category: ";
	char category[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(category,100,'\n');
	int i=0,count=0;
	while (data_book[i][5][0]!='\0') {
		if (compare_char_array(data_book[i][5],category))
			count+=charArrayToNumber(data_book[i][7]);
		i++;
	}
	std::cout<<"Total number of books by category: "<<count<<std::endl;
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
