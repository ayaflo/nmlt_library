#include <iostream>
#include <iomanip>
#include "Data.h"
#include "Reader.h"
#include "Book.h"
#include "Transaction.h"
#include "Function.h"
//#include <cstdlib>
void main_menu(char data_reader[100][9][100],char data_book[100][8][100],char data_transaction[100][6][100]);
void menu_reader(char data_reader[100][9][100],char data_book[100][8][100],char data_transaction[100][6][100]) {
    clearConsole();
    print_logo();
    //std::cout<<"\033[0;10H";
    std::cout<<"Reader Management\n"
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
    std::cout<<"Book Management\n"
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
    std::cout<<"Transaction\n"
    <<"1. Borrow book\n"
    <<"2. Return book\n"
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
    std::cout<<"Statistic\n"
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
    // printf("\e[0;30mBlack \e[1;30mbold Black \e[0;90mhigh intensity Black\n");
    // printf("\e[0;31mRed \e[1;31mbold Red \e[0;91mhigh intensity Red\n");
    // printf("\e[0;32mGreen \e[1;32mbold Green \e[0;92mhigh intensity Green\n");
    // printf("\e[0;33mYellow \e[1;33mbold Yellow \e[0;93mhigh intensity Yellow\n");
    // printf("\e[0;34mBlue \e[1;34mbold Blue \e[0;94mhigh intensity Blue\n");
    // printf("\e[0;35mPurple \e[1;35mbold Purple \e[0;95mhigh intensity Purple\n");
    // printf("\e[0;36mCyan \e[1;36mbold Cyan \e[0;96mhigh intensity Cyan\n");
    // printf("\e[0;37mWhite \e[1;37mbold White \e[0;97mhigh intensity White\n");
    // for (int r = 0; r < 256; r += 1)
    // for (int g = 0; g < 256; g += 1)
    // for (int b = 0; b < 256; b += 1)
    //     std::printf(("\e[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m" +"█").c_str());
    //std::cout<<"\033[10;10H";
    print_logo();
    std::cout<<"╔══════════════════════════╗\n"
             <<"║       HCMUS Library      ║\n"
             <<"╚══════════════════════════╝\n"
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
    system("chcp 65001");
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


    // int as;
    // std::cin>>as;
    return 0;
}