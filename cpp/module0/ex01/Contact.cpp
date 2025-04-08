#include "Contact.hpp"

Contact::Contact(){}

Contact::Contact(std::string f, std::string l, std::string n, std::string p, std::string s)
	: firstName(f), lastName(l), nickName(n), phoneNumber(p), secret(s) {}

std::string Contact::getFirstName() const {return this->firstName;}

std::string Contact::getLastName() const {return this->lastName;}

std::string Contact::getNickName() const {return this->nickName;}

std::string Contact::getPhoneNumber() const {return this->phoneNumber;}

std::string Contact::getSecret() const {return this->secret;}