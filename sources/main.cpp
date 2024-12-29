#include <iostream>
#include <iomanip>
#include "Data.h"
#include "Reader.h"
#include "Book.h"
#include "Transaction.h"
#include "Function.h"
bool main_menu(data_reader reader[],data_book book[],data_transaction transaction[]);
void menu_reader(data_reader reader[],data_book book[],data_transaction transaction[]) {
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
                case1_view_all_readers(reader);
            }
            break;
            case 2: {
                case2_add_reader(reader);
            }
            break;
            case 3: {
                case3_edit_reader(reader);
            }
            break;
            case 4: {
                case4_delete_reader(reader);
            }
            break;
            case 5: {
                case5_search_reader(reader);
            }
            break;
            case 6:{
                case6_search_reader(reader);
            }
            break;
            case 0: {
                std::cout << "Returning to main menu...\n";
                bool i=main_menu(reader,book,transaction);
            }
            break;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }

}
void menu_book(data_reader reader[],data_book book[],data_transaction transaction[]) {
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
              case1_view_all_books(book);
            }
            break;
            case 2: {
                case2_add_book(book);
            }
            break;
            case 3:{
                case3_edit_book(book);
            }
            break;
            case 4:{
                case4_delete_book(book);
            }
            break;
            case 5:{
                case5_search_book(book);
            }
            break;
            case 6:{
               case6_search_book(book);
            }
            break;
            case 0: {
                std::cout << "Returning to main menu...\n";
                bool i=main_menu(reader,book,transaction);
            }
            break;
            default: {
                std::cout << "Invalid choice! Try again.\n";
                //menu_book();
            }
        }
}
void menu_transaction(data_reader reader[],data_book book[],data_transaction transaction[]) {
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
            case1_borrow_transaction(transaction);
        }
        break;
        case 2: {
           case2_return_transaction(transaction,book);
        }
        break;
        case 3: {
            case3_view_transaction(transaction);
        }
        break;
        case 0: {
            std::cout << "Returning to main menu...\n";
            bool i=main_menu(reader,book,transaction);
        }
        break;
        default:
            std::cout << "Invalid choice! Try again.\n";
    }
}
void menu_statistic(data_reader reader[],data_book book[],data_transaction transaction[]) {
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
              case1_statistic(book);
            }
            break;
            case 2: {
                case2_statistic(book);
            }
            break;
            case 3: {
               case3_statistic(reader);
            }
            break;
            case 4: {
               case4_statistic(reader);
            }
            break;
            case 5: {
                case5_statistics(transaction);
            }
            break;
            case 6: {
                case6_statistics(transaction);
            }
            break;
            case 0: {
                std::cout << "Returning to main menu...\n";
                bool i=main_menu(reader,book,transaction);
            }
            break;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }
}

bool main_menu(data_reader reader[],data_book book[],data_transaction transaction[]) {
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
        menu_reader(reader,book,transaction);
        break;
        case 2:
            clearConsole();
        menu_book(reader,book,transaction);
        break;
        case 3:
            clearConsole();
        menu_transaction(reader,book,transaction);
        //do something
        break;
        case 4:
            clearConsole();
        menu_statistic(reader,book,transaction);
        break;
        case 0:{
        clearConsole();
        std::cout << "Exiting the system...\n";
        return false;
        }
        break;
        default:
            std::cout << "Invalid choice! Try again.\n";
    }
    return true;
}
int main()
{
    char file_reader[]="../Data/data_reader.txt";
    char file_book[]="../Data/data_book.txt";
    char file_transaction[]="../Data/data_transaction.txt";
    char file_reader_output[]="../Output/data_reader_output.txt";
    char file_book_output[]="../Output/data_book_output.txt";
    char file_transaction_output[]="../Output/data_transaction_output.txt";
    setColSizeConsole();
    //get data of reader
    data_reader reader[100];
    read_data_reader(file_reader,reader);
    // //get data of book
    data_book book[100];
     read_data_book(file_book,book);
    // //get data of transaction
    data_transaction transaction[100];
    read_data_transaction(file_transaction,transaction);

    while (main_menu(reader,book,transaction)) {}
    write_data_book(file_book_output,book);
    write_data_transaction(file_transaction_output,transaction);
    write_data_reader(file_reader_output,reader);
    return 0;
}