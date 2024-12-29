#include "Book.h"
#include <iostream>
#include <iomanip>
#include "Function.h"
void edit_book(char find_ISBN[],data_book book[],char ISBN[],char title[], char author[],char publisher[],char year[],char category[],char price[],char numberOfBooks[]) {
	unsigned int i=0,location=0;
	//find the reader who need to be edited
	bool check=false;

	while (book[location].ISBN[0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; book[location].ISBN[j] != '\0' || find_ISBN[j] != '\0'; ++j) {
			if (book[location].ISBN[j] != find_ISBN[j]) {
				check=false;
				break;
			}
		}
		if (check==true) {
			break;
		}
		location++;
		if (book[location].ISBN[0]=='\0') {
			std::cout<<"Error: Cannot find ISBN of book!\n";
			return;
		}
	}
	if (book[location].ISBN[0]=='\0')
		return;
	//edit book's information
	while (ISBN[i]!='\0') {
		book[location].ISBN[i]=ISBN[i];
		i++;
	}
	book[location].ISBN[i]='\0';
	i=0;
	while (title[i]!='\0') {
		book[location].title[i]=title[i];
		i++;
	}
	book[location].title[i]='\0';
	i=0;
	while (author[i]!='\0') {
		book[location].author[i]=author[i];
		i++;
	}
	book[location].author[i]='\0';
	i=0;
	while (publisher[i]!='\0') {
		book[location].publisher[i]=publisher[i];
		i++;
	}
	book[location].publisher[i]='\0';
	i=0;
	while (year[i]!='\0') {
		book[location].year[i]=year[i];
		i++;
	}
	book[location].year[i]='\0';
	i=0;
	while (category[i]!='\0') {
		book[location].category[i]=category[i];
		i++;
	}
	book[location].category[i]='\0';
	i=0;
	while (price[i]!='\0') {
		book[location].price[i]=price[i];
		i++;
	}
	book[location].price[i]='\0';
	i=0;
	while (numberOfBooks[i]!='\0') {
		book[location].numberOfBooks[i]=numberOfBooks[i];
		i++;
	}
	book[location].numberOfBooks[i]='\0';
	std::cout << "Edit book successfully!\n";
}
void add_book(data_book book[],char ISBN[],char title[], char author[],char publisher[],char year[],char category[],char price[],char numberOfBooks[]) {
	unsigned int i=0,location=-1;
	do {
		location++;
		if (book[location].ISBN[0]=='\0') {
			//edit book's information
			i=0;
			while (ISBN[i]!='\0') {
				book[location].ISBN[i]=ISBN[i];
				i++;
			}
			i=0;
			while (title[i]!='\0') {
				book[location].title[i]=title[i];
				i++;
			}
			i=0;
			while (author[i]!='\0') {
				book[location].author[i]=author[i];
				i++;
			}
			i=0;
			while (publisher[i]!='\0') {
				book[location].publisher[i]=publisher[i];
				i++;
			}
			i=0;
			while (year[i]!='\0') {
				book[location].year[i]=year[i];
				i++;
			}
			i=0;
			while (category[i]!='\0' ) {
				book[location].category[i]=category[i];
				i++;
			}
			i=0;
			while (price[i]!='\0') {
				book[location].price[i]=price[i];
				i++;
			}
			i=0;
			while (numberOfBooks[i]!='\0') {
				book[location].numberOfBooks[i]=numberOfBooks[i];
				i++;
			}
			break;
		}

	}while (book[location].ISBN[0]!='\0' && location<99);
	std::cout << "Add book successfully!\n";
}
void remove_book(const char find_ISBN[],data_book book[]) {
		unsigned int i=0,location=0;
	//find the reader who need to be removed
	bool check=false;
	while (book[location].ISBN[0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; book[location].ISBN[j] != '\0' || find_ISBN[j] != '\0'; ++j) {
			if (book[location].ISBN[j] != find_ISBN[j]) {
				check=false;
				break;
			}
		}
		if (check==true) {
			break;
		}
		location++;
		if (book[location].ISBN[0]=='\0') {
			std::cout<<"Error: Cannot find ISBN of book!\n";
			return;
		}
	}
	while (book[location+1].ISBN[0]!='\0') {
		//copy continous book into current book
		i=0;
		while (book[location+1].ISBN[i]!='\0') {
			book[location].ISBN[i]=book[location+1].ISBN[i];
			i++;
		}
		book[location].ISBN[i]='\0';
		i=0;
		while (book[location+1].title[i]!='\0') {
			book[location].title[i]=book[location+1].title[i];
			i++;
		}
		book[location].title[i]='\0';
		i=0;
		while (book[location+1].author[i]!='\0') {
			book[location].author[i]=book[location+1].author[i];
			i++;
		}
		book[location].author[i]='\0';
		i=0;
		while (book[location+1].publisher[i]!='\0') {
			book[location].publisher[i]=book[location+1].publisher[i];
			i++;
		}
		book[location].publisher[i]='\0';
		i=0;
		while (book[location+1].year[i]!='\0') {
			book[location].year[i]=book[location+1].year[i];
			i++;
		}
		book[location].year[i]='\0';
		i=0;
		while (book[location+1].category[i]!='\0') {
			book[location].category[i]=book[location+1].category[i];
			i++;
		}
		book[location].category[i]='\0';
		i=0;
		while (book[location+1].price[i]!='\0') {
			book[location].price[i]=book[location+1].price[i];
			i++;
		}
		book[location].price[i]='\0';
		i=0;
		while (book[location+1].numberOfBooks[i]!='\0') {
			book[location].numberOfBooks[i]=book[location+1].numberOfBooks[i];
			i++;
		}
		book[location].numberOfBooks[i]='\0';

		location++;
	}
	//delete the last book
	book[location].ISBN[0]='\0';
	book[location].title[0]='\0';
	book[location].author[0]='\0';
	book[location].publisher[0]='\0';
	book[location].year[0]='\0';
	book[location].category[0]='\0';
	book[location].price[0]='\0';
	book[location].numberOfBooks[0]='\0';
	std::cout << "Delete Reader "<<find_ISBN<<" successfully!\n";
}
int search_ISBN_book(const char ISBN[],const data_book book[]) {
	bool check=false;
	int i=0;
	while (book[i].ISBN[0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; book[i].ISBN[j] != '\0' || ISBN[j] != '\0'; ++j) {
			if (book[i].ISBN[j] != ISBN[j]) {
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
int search_title_book(const char title[],const data_book book[]) {
	bool check=false;
	int i=0;
	while (book[i].title[0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; book[i].title[j] != '\0' || title[j] != '\0'; ++j) {
			if (book[i].title[j] != title[j]) {
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
int total_book(const data_book book[]) {
	int count=0,i=0;
	while (book[i].numberOfBooks[0]!='\0') {
		count+=charArrayToNumber(book[i].numberOfBooks);
		i++;
	}
	return count;
}
int total_book_category(const data_book book[],const char category[]) {
	int count=0;
	bool check=false;
	int i=0;
	while (book[i].category[0]!='\0') {
		check=true;
		// compare two char arrays to find book follow category
		for (int j = 0; book[i].category[j] != '\0' || category[j] != '\0'; ++j) {
			if (book[i].category[j] != category[j]) {
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
void display_book(data_book book) {
	std::cout<<std::setw(10)<<book.ISBN;
	std::cout<<std::setw(80)<<book.title;
	std::cout<<std::setw(30)<<book.author;
	std::cout<<std::setw(30)<<book.publisher;
	std::cout<<std::setw(10)<<book.year;
	std::cout<<std::setw(20)<<book.category;
	std::cout<<std::setw(20)<<book.price;
	std::cout<<std::setw(15)<<book.numberOfBooks;
	std::cout<<std::endl;
}
void display_all_book(const data_book book[]) {
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
	while (book[i].ISBN[0]!='\0') {
		display_book(book[i]);
		i++;
	}
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
}
void case1_view_all_books(const data_book book[]) {
	clearConsole();
	std::cout << "Viewing books...\n";
	display_all_book(book);
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case2_add_book(data_book book[]) {
	clearConsole();
	display_all_book(book);
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
	add_book(book,ISBN,title,author,publisher,year,category,price,numberOfBooks);

	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case3_edit_book(data_book book[]) {
	clearConsole();
	display_all_book(book);
	std::cout << "Editing Book\n"
		  <<"Enter edited book's ISBN: ";
	char find_ISBN[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(find_ISBN,100,'\n');
	char ISBN[100],title[100],author[100],publisher[100],year[100],category[100],price[100],numberOfBooks[100];
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
	edit_book(find_ISBN,book,ISBN,title,author,publisher,year,category,price,numberOfBooks);
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case4_delete_book(data_book book[]) {
	clearConsole();
	display_all_book(book);
	std::cout << "Deleting book\n"
			  <<"Enter deleted book's ISBN: ";
	char find_ISBN[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(find_ISBN,100,'\n');
	remove_book(find_ISBN,book);
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case5_search_book(data_book book[]) {
	clearConsole();
	display_all_book(book);
	std::cout << "Searching book by book's ISBN...\n";
	std::cout<<"Enter ISBN of book: ";
	char find_ISBN[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(find_ISBN,100,'\n');
	int location=search_ISBN_book(find_ISBN,book);
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
		display_book(book[location]);
		std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	}
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case6_search_book(data_book book[]) {
	clearConsole();
	display_all_book(book);
	std::cout << "Searching book by book's title...\n";
	std::cout<<"Enter book's title: ";
	char find_title[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(find_title,100,'\n');
	int location=search_title_book(find_title,book);
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
		display_book(book[location]);
		std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	}
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case1_statistic(data_book book[]) {
	clearConsole();
	display_all_book(book);
	std::cout<<"Statistic:\n";
	std::cout<<"Statistics on the number of books: "<<total_book(book)<<std::endl;
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case2_statistic(data_book book[]) {
	clearConsole();
	display_all_book(book);
	std::cout << "Statistics on books by category...\n";
	std::cout<<"Enter category: ";
	char category[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(category,100,'\n');
	int i=0,count=0;
	while (book[i].category[0]!='\0') {
		if (compare_char_array(book[i].category,category))
			count+=charArrayToNumber(book[i].numberOfBooks);
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