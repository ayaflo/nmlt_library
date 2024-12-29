#include "Reader.h"
#include <iomanip>
#include "Function.h"
#include <iostream>

void edit_reader(char find_id[],data_reader reader[],char id[],char name[],char cmnd[],char birthdate[],char gender[],char email[],char address[],char issue_date[],char expiry_date[]) {
	unsigned int i=0,location=0;
	//find the reader who need to be edited
	bool check=false;
	while (reader[location].id[0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; reader[location].id[j] != '\0' || find_id[j] != '\0'; ++j) {
			if (reader[location].id[j] != find_id[j]) {
				check=false;
				break;
			}
		}
		if (check==true) {
			//output infor about the reader
			break;
		}
		location++;
		if (reader[location].id[0]=='\0') {
			std::cout<<"Error: Cannot find id of reader"<<std::endl;
		}
	}
	if (reader[location].id[0]=='\0')
		return;
	//edit reader's information
	while (id[i]!='\0') {
		reader[location].id[i]=id[i];
		i++;
	}
	reader[location].id[i]='\0';
	i=0;
	while (name[i]!='\0') {
		reader[location].name[i]=name[i];
		i++;
	}
	reader[location].name[i]='\0';
	i=0;
	while (cmnd[i]!='\0') {
		reader[location].cmnd[i]=cmnd[i];
		i++;
	}
	reader[location].cmnd[i]='\0';
	i=0;
	while (birthdate[i]!='\0') {
		reader[location].birthdate[i]=birthdate[i];
		i++;
	}
	reader[location].birthdate[i]='\0';
	i=0;
	while (gender[i]!='\0') {
		reader[location].gender[i]=gender[i];
		i++;
	}
	reader[location].gender[i]='\0';
	i=0;
	while (email[i]!='\0') {
		reader[location].email[i]=email[i];
		i++;
	}
	reader[location].email[i]='\0';
	i=0;
	while (address[i]!='\0') {
		reader[location].address[i]=address[i];
		i++;
	}
	reader[location].address[i]='\0';
	i=0;
	while (issue_date[i]!='\0') {
		reader[location].issue_date[i]=issue_date[i];
		i++;
	}
	reader[location].issue_date[i]='\0';
	i=0;
	while (expiry_date[i]!='\0') {
		reader[location].expiry_date[i]=expiry_date[i];
		i++;
	}
	reader[location].expiry_date[i]='\0';
	std::cout << "Edit reader successfully!\n";
}
void add_reader(data_reader reader[],char id[],char name[],char cmnd[],char birthdate[],char gender[],char email[],char address[],char issue_date[],char expiry_date[]) {
	unsigned int i=0,location=-1;
	do {
		location++;
		if (reader[location].id[0]=='\0') {
			//edit reader's information
			i=0;
			while (id[i]!='\0') {
				reader[location].id[i]=id[i];
				i++;
			}
			i=0;
			while (name[i]!='\0') {
				reader[location].name[i]=name[i];
				i++;
			}
			i=0;
			while (cmnd[i]!='\0') {
				reader[location].cmnd[i]=cmnd[i];
				i++;
			}
			i=0;
			while (birthdate[i]!='\0') {
				reader[location].birthdate[i]=birthdate[i];
				i++;
			}
			i=0;
			while (gender[i]!='\0') {
				reader[location].gender[i]=gender[i];
				i++;
			}
			i=0;
			while (email[i]!='\0' ) {
				reader[location].email[i]=email[i];
				i++;
			}
			i=0;
			while (address[i]!='\0') {
				reader[location].address[i]=address[i];
				i++;
			}
			i=0;
			while (issue_date[i]!='\0') {
				reader[location].issue_date[i]=issue_date[i];
				i++;
			}
			i=0;
			while (expiry_date[i]!='\0') {
				reader[location].expiry_date[i]=expiry_date[i];
				i++;
			}
			break;
		}

	}while (reader[location].id[0]!='\0' && location<99);
	std::cout << "Add reader successfully!\n";
}
void remove_reader(char find_id[],data_reader reader[]) {
	unsigned int i=0,location=0;
	//find the reader who need to be removed
	bool check=false;
	while (reader[location].id[0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; reader[location].id[j] != '\0' || find_id[j] != '\0'; ++j) {
			if (reader[location].id[j] != find_id[j]) {
				check=false;
				break;
			}
		}
		if (check==true) {
			break;
		}
		location++;
		if (reader[location].id[0]=='\0') {
			std::cout << "Error: Cannot find the id of reader!\n";
			return;
		}

	}
	while (reader[location+1].id[0]!='\0') {
		//copy continous reader into current reader
		i=0;
		while (reader[location+1].id[i]!='\0') {
			reader[location].id[i]=reader[location+1].id[i];
			i++;
		}
		reader[location].id[i]='\0';
		i=0;
		while (reader[location+1].name[i]!='\0') {
			reader[location].name[i]=reader[location+1].name[i];
			i++;
		}
		reader[location].name[i]='\0';
		i=0;
		while (reader[location+1].cmnd[i]!='\0') {
			reader[location].cmnd[i]=reader[location+1].cmnd[i];
			i++;
		}
		reader[location].cmnd[i]='\0';
		i=0;
		while (reader[location+1].birthdate[i]!='\0') {
			reader[location].birthdate[i]=reader[location+1].birthdate[i];
			i++;
		}
		reader[location].birthdate[i]='\0';
		i=0;
		while (reader[location+1].gender[i]!='\0') {
			reader[location].gender[i]=reader[location+1].gender[i];
			i++;
		}
		reader[location].gender[i]='\0';
		i=0;
		while (reader[location+1].email[i]!='\0') {
			reader[location].email[i]=reader[location+1].email[i];
			i++;
		}
		reader[location].email[i]='\0';
		i=0;
		while (reader[location+1].address[i]!='\0') {
			reader[location].address[i]=reader[location+1].address[i];
			i++;
		}
		reader[location].address[i]='\0';
		i=0;
		while (reader[location+1].issue_date[i]!='\0') {
			reader[location].issue_date[i]=reader[location+1].issue_date[i];
			i++;
		}
		reader[location].issue_date[i]='\0';
		i=0;
		while (reader[location+1].expiry_date[i]!='\0') {
			reader[location].expiry_date[i]=reader[location+1].expiry_date[i];
			i++;
		}

		location++;
	}
	//delete the last reader
	reader[location].id[0]='\0';
	reader[location].name[0]='\0';
	reader[location].cmnd[0]='\0';
	reader[location].birthdate[0]='\0';
	reader[location].gender[0]='\0';
	reader[location].email[0]='\0';
	reader[location].address[0]='\0';
	reader[location].issue_date[0]='\0';
	reader[location].expiry_date[0]='\0';
	std::cout << "Delete Reader "<<find_id<<" successfully!\n";
}
int search_cmnd_reader(const char cmnd[],const data_reader reader[]) {
	bool check=false;
	int i=0;
	while (reader[i].cmnd[0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; reader[i].cmnd[j] != '\0' || cmnd[j] != '\0'; ++j) {
			if (reader[i].cmnd[j] != cmnd[j]) {
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
int search_name_reader(const char name[],const data_reader reader[]) {
	bool check=false;
	int i=0;
	while (reader[i].name[0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; reader[i].name[j] != '\0' || name[j] != '\0'; ++j) {
			if (reader[i].name[j] != name[j]) {
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
int total_reader(const data_reader reader[]) {
	int count=0;
	while (reader[count].id[0]!='\0') {
		count++;
	}
	return count;
}
int total_reader_gender(const char gender[],const data_reader reader[]) {
	int count=0;
	bool check=false;
	int i=0;
	while (reader[i].gender[0]!='\0') {
		check=true;
		// compare two char arrays
		for (int j = 0; reader[i].gender[j] != '\0' || gender[j] != '\0'; ++j) {
			if (reader[i].gender[j] != gender[j]) {
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
void display_reader(const data_reader reader) {
	std::cout<<std::setw(10)<<reader.id;
	std::cout<<std::setw(25)<<reader.name;
	std::cout<<std::setw(15)<<reader.cmnd;
	std::cout<<std::setw(15)<<reader.birthdate;
	std::cout<<std::setw(10)<<reader.gender;
	std::cout<<std::setw(40)<<reader.email;
	std::cout<<std::setw(70)<<reader.address;
	std::cout<<std::setw(15)<<reader.issue_date;
	std::cout<<std::setw(15)<<reader.expiry_date;
	std::cout<<std::endl;
}
void display_all_reader(const data_reader reader[]) {
	//print out the header
	std::cout<<std::left<<std::setw(10)<<"ID"
	<<std::setw(25)<<"Name"
	<<std::setw(15)<<"CMND/CCCD"
	<<std::setw(15)<<"Birthdate"
	<<std::setw(10)<<"Gender"
	<<std::setw(40)<<"Email"
	<<std::setw(70)<<"Address"
	<<std::setw(15)<<"Issue Date"
	<<std::setw(15)<<"Expiry Date"<<std::endl;
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	int i=0;
	while (reader[i].id[0]!='\0') {
		display_reader(reader[i]);
		i++;
	}
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;

}

void case1_view_all_readers(const data_reader reader[]) {
	clearConsole();
	std::cout << "Viewing readers...\n";
	display_all_reader(reader);
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case2_add_reader(data_reader reader[]) {
	clearConsole();
	display_all_reader(reader);
	std::cout << "Adding reader...\n";

	char id[100],name[100],cmnd[100],birthdate[100],gender[100],email[100],address[100],issue_date[100],expiry_date[100];
	std::cin.ignore();
	std::cout<<"Enter ID: ";
	std::cin.getline(id,100);
	std::cout<<"Enter Name: ";
	std::cin.getline(name,100);
	std::cout<<"Enter CMND: ";
	std::cin.getline(cmnd,100);
	std::cout<<"Enter Birthdate: ";
	std::cin.getline(birthdate,100);
	std::cout<<"Enter Gender: ";
	std::cin.getline(gender,100);
	std::cout<<"Enter Email: ";
	std::cin.getline(email,100);
	std::cout<<"Enter Address: ";
	std::cin.getline(address,100);
	std::cout<<"Enter ISSUE Date: ";
	std::cin.getline(issue_date,100);
	int day,month,year;
	parseDate(issue_date,day,month,year);
	formatDate(day,month,year+4,expiry_date);
	add_reader(reader,id,name,cmnd,birthdate,gender,email,address,issue_date,expiry_date);

	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case3_edit_reader(data_reader reader[]) {
	clearConsole();
	display_all_reader(reader);
	std::cout << "Editing Reader\n"
		  <<"Enter edited reader's ID: ";
	char find_id[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(find_id,100,'\n');
	char id[100],name[100],cmnd[100],birthdate[100],gender[100],email[100],address[100],issue_date[100],expiry_date[100];
	//std::cin.ignore();
	std::cout<<"Enter new ID: ";
	std::cin.getline(id,100);
	std::cout<<"Enter new Name: ";
	std::cin.getline(name,100);
	std::cout<<"Enter new CMND: ";
	std::cin.getline(cmnd,100);
	std::cout<<"Enter new Birthdate: ";
	std::cin.getline(birthdate,100);
	std::cout<<"Enter new Gender: ";
	std::cin.getline(gender,100);
	std::cout<<"Enter new Email: ";
	std::cin.getline(email,100);
	std::cout<<"Enter new Address: ";
	std::cin.getline(address,100);
	std::cout<<"Enter new ISSUE Date: ";
	std::cin.getline(issue_date,100);
	int day,month,year;
	parseDate(issue_date,day,month,year);
	formatDate(day,month,year+4,expiry_date);
	edit_reader(find_id,reader,id,name,cmnd,birthdate,gender,email,address,issue_date,expiry_date);

	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case4_delete_reader(data_reader reader[]) {
	clearConsole();
	display_all_reader(reader);
	std::cout << "Deleting Reader\n"
			  <<"Enter deleted reader's ID: ";
	char find_id[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(find_id,100,'\n');
	remove_reader(find_id,reader);

	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case5_search_reader(data_reader reader[]) {
	 clearConsole();
	display_all_reader(reader);
                std::cout << "Searching reader by reader's CMND/CCCD...\n";
				std::cout<<"Enter CMND/CCCD: ";
                char find_cmnd[100];
                std::cin.ignore(2,'\n');
                std::cin.getline(find_cmnd,100,'\n');
                int location=search_cmnd_reader(find_cmnd,reader);
                if(location==-1)
                    std::cout<<"No such reader\n";
                else {
                	std::cout<<std::endl;
                	std::cout<<std::left<<std::setw(10)<<"ID"
							<<std::setw(25)<<"Name"
							<<std::setw(15)<<"CMND/CCCD"
							<<std::setw(15)<<"Birthdate"
                			<<std::setw(10)<<"Gender"
                			<<std::setw(40)<<"Email"
							<<std::setw(70)<<"Address"
							<<std::setw(15)<<"Issue Date"
                			<<std::setw(15)<<"Expiry Date"<<std::endl;
                    std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
                    display_reader(reader[location]);
                	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
                }
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case6_search_reader(data_reader reader[]) {
	clearConsole();
	display_all_reader(reader);
	std::cout << "Searching reader by reader's name...\n";
	std::cout<<"Enter reader's name: ";
	char find_name[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(find_name,100,'\n');
	int location=search_name_reader(find_name,reader);
	if(location==-1)
		std::cout<<"No such reader\n";
	else {
		std::cout<<std::endl;
		std::cout<<std::left<<std::setw(10)<<"ID"
				 <<std::setw(25)<<"Name"
				 <<std::setw(15)<<"CMND/CCCD"
				 <<std::setw(15)<<"Birthdate"
				 <<std::setw(10)<<"Gender"
				 <<std::setw(40)<<"Email"
				 <<std::setw(70)<<"Address"
				 <<std::setw(15)<<"Issue Date"
				 <<std::setw(15)<<"Expiry Date"<<std::endl;
		std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
		display_reader(reader[location]);
		std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	}
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}

void case3_statistic(data_reader reader[]) {
	clearConsole();
	display_all_reader(reader);
	std::cout<<"Statistics on the number of readers: "<<total_reader(reader)<<std::endl;
	std::cout << std::setfill('-') << std::setw(220) << "-" << std::setfill(' ') << std::endl;
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
void case4_statistic(data_reader reader[]) {
	clearConsole();
	display_all_reader(reader);
	std::cout << "Statistics on readers by gender...\n";
	std::cout<<"Enter gender: ";
	char gender[100];
	std::cin.ignore(2,'\n');
	std::cin.getline(gender,100,'\n');
	int i=0,count=0;
	while (reader[i].gender[0]!='\0') {
		if (compare_char_array(reader[i].gender,gender))
			count++;
		i++;
	}
	std::cout<<"Total number of readers by gender: "<<count<<std::endl;
	std::cout<<"Enter 0 to return main menu...\n";
	int choice;
	std::cin>>choice;
	while (choice!=0) {
		std::cin>>choice;
	}
}
