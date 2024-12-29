
#ifndef DATA_H
#define DATA_H
#include <fstream>
#include <iostream>
#include "Function.h"

inline void read_data_reader(char filename[],data_reader reader[]) {
	std::ifstream dataFile(filename);
	if (!dataFile.is_open()) {
		std::cerr << "Error opening file " << filename << std::endl;
	}
	else {
		char temp;
		int i=0;
		while (!dataFile.eof()) {
			dataFile.getline(reader[i].id,100,';'); //get id
			dataFile.getline(reader[i].name,100,';'); //get name
			dataFile.getline(reader[i].cmnd,100,';'); //get cmnd
			dataFile.getline(reader[i].birthdate,100,';'); //get birthdate
			dataFile.getline(reader[i].gender,100,';'); //get gender
			dataFile.getline(reader[i].email,100,';'); //get email
			dataFile.getline(reader[i].address,100,';'); //get address
			dataFile.getline(reader[i].issue_date,100,'\n'); //get issue_date
			// dataFile.getline(reader[i][8],100,'\n'); //get expiry_date
			set_expiry_date(reader[i]);
			i++;
		}	
	}
}
inline void read_data_book(char filename[],data_book book[]) {
	std::ifstream dataFile(filename);
	if (!dataFile.is_open()) {
		std::cerr << "Error opening file " << filename << std::endl;
	}
	else {
		char temp;
		int i=0;
		while (!dataFile.eof()) {
			dataFile.getline(book[i].ISBN,100,';'); //get ISBN
			dataFile.getline(book[i].title,100,';'); //get title
			dataFile.getline(book[i].author,100,';'); //get author
			dataFile.getline(book[i].publisher,100,';'); //get publisher
			dataFile.getline(book[i].year,100,';'); //get year
			dataFile.getline(book[i].category,100,';'); //get category
			dataFile.getline(book[i].price,100,';'); //get price
			dataFile.getline(book[i].numberOfBooks,100,'\n'); //get number of books
			i++;
		}
	}
}
inline void read_data_transaction(char filename[],data_transaction transaction[]) {
	std::ifstream dataFile(filename);
	if (!dataFile.is_open()) {
		std::cerr << "Error opening file " << filename << std::endl;
	}
	else {
		char temp;
		int i=0;
		while (!dataFile.eof()) {
			dataFile.getline(transaction[i].idOfReader,100,';'); //get idOfReader
			std::cout<<transaction[i].idOfReader<<std::endl;
			dataFile.getline(transaction[i].borrow_date,100,';'); //get borrow_date
			std::cout<<transaction[i].borrow_date<<std::endl;
			dataFile.getline(transaction[i].return_date,100,';'); //get return_date
			std::cout<<transaction[i].return_date<<std::endl;
			dataFile.getline(transaction[i].actual_return_date,100,';'); //get actual_return_date
			std::cout<<transaction[i].actual_return_date<<std::endl;
			dataFile.getline(transaction[i].ISBNs,100,';'); //get ISBNs
			std::cout<<transaction[i].ISBNs<<std::endl;
			dataFile.getline(transaction[i].fine_amount,100,'\n'); //get fine_amount
			std::cout<<transaction[i].fine_amount<<std::endl;
			i++;
		}
	}
}
inline void write_data_reader(char filename[],data_reader reader[]) {
	std::ofstream dataFile(filename);
	int i=0;
	while (reader[i].id[0]!='\0') {
		dataFile<<reader[i].id<<';';
		dataFile<<reader[i].name<<';';
		dataFile<<reader[i].cmnd<<';';
		dataFile<<reader[i].birthdate<<';';
		dataFile<<reader[i].gender<<';';
		dataFile<<reader[i].email<<';';
		dataFile<<reader[i].address<<';';
		dataFile<<reader[i].issue_date<<'\n';
		i++;
	}
	dataFile.close();
}
inline void write_data_book(char filename[],data_book book[]) {
	std::ofstream dataFile(filename);
	int i=0;
	while (book[i].ISBN[0]!='\0') {
		dataFile<<book[i].ISBN<<';';
		dataFile<<book[i].title<<';';
		dataFile<<book[i].author<<';';
		dataFile<<book[i].publisher<<';';
		dataFile<<book[i].year<<';';
		dataFile<<book[i].category<<';';
		dataFile<<book[i].price<<';';
		dataFile<<book[i].numberOfBooks<<'\n';
		i++;
	}
	dataFile.close();
}
inline void write_data_transaction(char filename[],data_transaction transaction[]) {
	std::ofstream dataFile(filename);
	int i=0;
	while (transaction[i].idOfReader[0]!='\0') {
		dataFile<<transaction[i].idOfReader<<';';
		dataFile<<transaction[i].borrow_date<<';';
		dataFile<<transaction[i].return_date<<';';
		dataFile<<transaction[i].actual_return_date<<';';
		dataFile<<transaction[i].ISBNs<<';';
		dataFile<<transaction[i].fine_amount<<'\n';
		i++;
	}
	dataFile.close();
}
#endif //DATA_H
