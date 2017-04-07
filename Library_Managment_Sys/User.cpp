#include<iostream>
#include <string>
#include "User.h"

////////////////////////////////////////
// Non-default Ctor
////////////////////////////////////////
LIBRARY::User::User(const std::string& user_name, const std::string& address, const std::string& phoneNum, const std::string& DOB)
	: m_user_name(user_name)
	, m_address(address)
	, m_phoneNum(phoneNum)
	, m_DOB(DOB)
{ }

////////////////////////////////////////
// GETTERS
////////////////////////////////////////
std::string LIBRARY::User::get_user_name() const
{
	return m_user_name;
}

std::string LIBRARY::User::get_address() const
{
	return m_address;
}

std::string LIBRARY::User::get_phoneNum() const
{
	return m_phoneNum;
}

std::string LIBRARY::User::get_DOB() const
{
	return m_DOB;
}

////////////////////////////////////////
// SETTERS
////////////////////////////////////////


void LIBRARY::User::print() const
{
	std::cout << "\n\t\t\t User Name: " << m_user_name;
	std::cout << "\n\t\t\t User Address: " << m_address;
	std::cout << "\n\t\t\t User Phone#: " << m_phoneNum;
	std::cout << "\n\t\t\t User DOB: " << m_DOB;
	std::cout << std::endl;
}