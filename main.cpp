#include <iostream>
#include <iomanip>
#include "Data.h"
#include "Reader.h"
#include "Book.h"
#include "Transaction.h"
#include "Function.h"
void main_menu(char data_reader[100][9][100],char data_book[100][8][100],char data_transaction[100][6][100]);
void menu_reader(char data_reader[100][9][100],char data_book[100][8][100],char data_transaction[100][6][100]) {
    clearConsole();
    print_logo();
    std::cout<<"[Reader Management]\n"
    <<"1. View the list of readers in the library\n"
    <<"2. Add a reader\n"
    <<"3. Edit a reader's information\n"
    <<"4. Delete a reader's information\n"
    <<"5. Search for a reader by CMND/CCCD number\n"
    <<"6. Search for a reader by name\n"
    <<"0. Main Menu\n";
    int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                case1_view_all_readers(data_reader);
            }
            break;
            case 2: {
                case2_add_reader(data_reader);
            }
            break;
            case 3: {
                case3_edit_reader(data_reader);
            }
            break;
            case 4: {
                case4_delete_reader(data_reader);
            }
            break;
            case 5: {
                case5_search_reader(data_reader);
            }
            break;
            case 6:{
                case6_search_reader(data_reader);
            }
            break;
            case 0:
                std::cout << "Returning to main menu...\n";
                 main_menu(data_reader,data_book,data_transaction);
            break;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }

}
void menu_book(char data_reader[100][9][100],char data_book[100][8][100],char data_transaction[100][6][100]) {
    clearConsole();
    print_logo();
    std::cout<<"[Book Management]\n"
    <<"1. View the list of books in the library\n"
    <<"2. Add a book\n"
    <<"3. Edit a book's information\n"
    <<"4. Delete a book's information\n"
    <<"5. Search for a book by ISBN\n"
    <<"6. Search for a book by title\n"
    <<"0. Main Menu\n";
    int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: {
              case1_view_all_books(data_book);
            }
            break;
            case 2: {
                case2_add_book(data_book);
            }
            break;
            case 3:{
                case3_edit_book(data_book);
            }
            break;
            case 4:{
                case4_delete_book(data_book);
            }
            break;
            case 5:{
                case5_search_book(data_book);
            }
            break;
            case 6:{
               case6_search_book(data_book);
            }
            break;
            case 0:
                std::cout << "Returning to main menu...\n";
                main_menu(data_reader,data_book,data_transaction);
            break;
            default: {
                std::cout << "Invalid choice! Try again.\n";
                //menu_book();
            }
        }
}
void menu_transaction(char data_reader[100][9][100],char data_book[100][8][100],char data_transaction[100][6][100]) {
    clearConsole();
    print_logo();
    std::cout<<"[Transaction]\n"
    <<"1. Borrow book\n"
    <<"2. Return book\n"
    <<"3. View transaction\n"
    <<"0. Main Menu\n";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            case1_borrow_transaction(data_transaction);
        }
        break;
        case 2: {
           case2_return_transaction(data_transaction,data_book);
        }
        break;
        case 3: {
            case3_view_transaction(data_transaction);
        }
        break;
        case 0: {
            std::cout << "Returning to main menu...\n";
            main_menu(data_reader,data_book,data_transaction);
        }
        break;
        default:
            std::cout << "Invalid choice! Try again.\n";
    }
}
void menu_statistic(char data_reader[100][9][100],char data_book[100][8][100],char data_transaction[100][6][100]) {
    clearConsole();
    print_logo();
    std::cout<<"[Statistic]\n"
    <<"1. Statistics on the number of books in the library\n"
    <<"2. Statistics on the number of books by category\n"
    <<"3. Statistics on the number of readers\n"
    <<"4. Statistics on the number of readers by gender\n"
    <<"5. Statistics on the number of books currently borrowed\n"
    <<"6. Statistics on the list of overdue readers\n"
    <<"0. Main Menu\n";
    int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: {
              case1_statistic(data_book);
            }
            break;
            case 2: {
                case2_statistic(data_book);
            }
            break;
            case 3: {
               case3_statistic(data_reader);
            }
            break;
            case 4: {
               case4_statistic(data_reader);
            }
            break;
            case 5: {
                case5_statistics(data_transaction);
            }
            break;
            case 6: {
                case6_statistics(data_transaction);
            }
            break;
            case 0: {
                std::cout << "Returning to main menu...\n";
                main_menu(data_reader,data_book,data_transaction);
            }
            break;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }
}

void main_menu(char data_reader[100][9][100],char data_book[100][8][100],char data_transaction[100][6][100]) {
    clearConsole();
    print_logo();
    std::cout<<"[Main Menu]\n"
             <<"1. Reader Management\n"
             <<"2. Book Management\n"
             <<"3. Borrowing and Returning Book\n"
             <<"4. Statistics\n"
             <<"0. Exit\n";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            clearConsole();
        menu_reader(data_reader,data_book,data_transaction);
        break;
        case 2:
            clearConsole();
        menu_book(data_reader,data_book,data_transaction);
        break;
        case 3:
            clearConsole();
        menu_transaction(data_reader,data_book,data_transaction);
        //do something
        break;
        case 4:
            clearConsole();
        menu_statistic(data_reader,data_book,data_transaction);
        break;
        case 0:{
        clearConsole();
        std::cout << "Exiting the system...\n";
        exit(0);
        }
        break;
        default:
            std::cout << "Invalid choice! Try again.\n";
    }
}
int main()
{
   // system("chcp 65001");
    setColSizeConsole();
    char file_reader[]="../Data/data_reader.txt";
    char file_book[]="../Data/data_book.txt";
    char file_transaction[]="../Data/data_transaction.txt";
    //get data of reader
    char data_reader[100][9][100];
    read_data_reader(file_reader,data_reader);
    // //get data of book
    char data_book[100][8][100];
     read_data_book(file_book,data_book);
    // //get data of transaction
    char data_transaction[100][6][100];
     read_data_transaction(file_transaction,data_transaction);

    while (true) {

        main_menu(data_reader,data_book,data_transaction);
    }
    return 0;
}