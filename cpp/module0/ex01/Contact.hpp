#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string secret;
	public:
		Contact();
		Contact(std::string f, std::string l, std::string n, std::string p, std::string s);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getSecret() const;
};

#endif