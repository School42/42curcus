#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int contactCount;
		int oldestIndex;
	public:
		PhoneBook();
		void addContact(const Contact &newcontact);
		void displayContacts() const;
		void displayContactDetails(int index) const;
		int  getTotalCount() const;
};

#endif