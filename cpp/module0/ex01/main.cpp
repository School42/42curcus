#include <iostream>
#include "PhoneBook.hpp"

std::string promptField(const std::string &fieldName) {
    std::string input;
    while (true) {
        std::cout << fieldName << ": ";
        std::getline(std::cin, input);
        if (std::cin.eof()) break;
        if (!input.empty()) break;
        std::cout << "Field cannot be empty. Try again.\n";
    }
    return input;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof()) break;
        if (command == "ADD") {
            std::string first = promptField("First Name");
            std::string last = promptField("Last Name");
            std::string nick = promptField("Nickname");
            std::string phone = promptField("Phone Number");
            std::string secret = promptField("Darkest Secret");
            Contact newContact(first, last, nick, phone, secret);
            phoneBook.addContact(newContact);
        }
        else if (command == "SEARCH") {
            if (phoneBook.getTotalCount() == 0) {
                std::cout << "PhoneBook is empty.\n";
                continue;
            }
            phoneBook.displayContacts();
            std::cout << "Enter index to view details: ";
            std::string indexStr;
            std::getline(std::cin, indexStr);
            int index;
            if (indexStr.length() == 1 && isdigit(indexStr[0]))
                index = indexStr[0] - '0';
            else
                index = -1;
            phoneBook.displayContactDetails(index);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "Unknown command. Try ADD, SEARCH, or EXIT.\n";
        }
    }
    return 0;
}
