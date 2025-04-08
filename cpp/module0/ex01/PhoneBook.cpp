#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
	contactCount = 0;
	oldestIndex = 0;
}

void PhoneBook::addContact(const Contact &newcontact) {
	if (contactCount < 8)
		contactCount++;
	contacts[oldestIndex] = newcontact;
	oldestIndex = (oldestIndex + 1) % 8;
}

void PhoneBook::displayContacts() const {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(10) << i << "|";

        std::string fields[3] = {
            contacts[i].getFirstName(),
            contacts[i].getLastName(),
            contacts[i].getNickName()
        };

        for (int j = 0; j < 3; j++) {
            std::string out = fields[j];
            if (out.length() > 10)
                out = out.substr(0, 9) + ".";
            std::cout << std::setw(10) << out << (j == 2 ? "\n" : "|");
        }
    }
}

void PhoneBook::displayContactDetails(int index) const {
	if (index < 0 || index >= contactCount){
		std::cout << "Invalid index." << std::endl;
        return;
	}
	const Contact &c = contacts[index];
    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickName() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getSecret() << std::endl;
}

int PhoneBook::getTotalCount() const {
	return (this->contactCount);
}