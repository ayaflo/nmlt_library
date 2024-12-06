
#ifndef DATA_H
#define DATA_H
#include <fstream>
#include <iostream>
#include "Function.h"
inline void read_data_reader(char filename[],char reader[100][9][100]) {
	std::ifstream dataFile(filename);
	if (!dataFile.is_open()) {
		std::cerr << "Error opening file " << filename << std::endl;
	}
	else {
		char temp;
		int i=0;
		while (!dataFile.eof()) {
			dataFile.getline(reader[i][0],100,';'); //get id
			dataFile.getline(reader[i][1],100,';'); //get name
			dataFile.getline(reader[i][2],100,';'); //get cmnd
			dataFile.getline(reader[i][3],100,';'); //get birthdate
			dataFile.getline(reader[i][4],100,';'); //get gender
			dataFile.getline(reader[i][5],100,';'); //get email
			dataFile.getline(reader[i][6],100,';'); //get address
			dataFile.getline(reader[i][7],100,'\n'); //get issue_date
			// dataFile.getline(reader[i][8],100,'\n'); //get expiry_date
			set_expiry_date(reader,i);
			i++;
		}
	}
}
inline void read_data_book(char filename[],char book[100][8][100]) {
	std::ifstream dataFile(filename);
	if (!dataFile.is_open()) {
		std::cerr << "Error opening file " << filename << std::endl;
	}
	else {
		char temp;
		int i=0;
		while (!dataFile.eof()) {
			dataFile.getline(book[i][0],100,';'); //get ISBN
			dataFile.getline(book[i][1],100,';'); //get title
			dataFile.getline(book[i][2],100,';'); //get author
			dataFile.getline(book[i][3],100,';'); //get publisher
			dataFile.getline(book[i][4],100,';'); //get year
			dataFile.getline(book[i][5],100,';'); //get category
			dataFile.getline(book[i][6],100,';'); //get price
			dataFile.getline(book[i][7],100,'\n'); //get number of books
			i++;
		}
	}
}
inline void read_data_transaction(char filename[],char transaction[100][6][100]) {
	std::ifstream dataFile(filename);
	if (!dataFile.is_open()) {
		std::cerr << "Error opening file " << filename << std::endl;
	}
	else {
		char temp;
		int i=0;
		while (!dataFile.eof()) {
			dataFile.getline(transaction[i][0],100,';'); //get idOfReader
			dataFile.getline(transaction[i][1],100,';'); //get borrow_date
			dataFile.getline(transaction[i][2],100,';'); //get return_date
			dataFile.getline(transaction[i][3],100,';'); //get actual_return_date
			dataFile.getline(transaction[i][4],100,';'); //get ISBNs
			dataFile.getline(transaction[i][5],100,'\n'); //get fine_amount
			i++;
		}
	}
}
#endif //DATA_H
