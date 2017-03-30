#include<iostream>
#include <string>
#include "Bill.h"

////////////////////////////////////////
// Non-default Ctor
////////////////////////////////////////
LIBRARY::Bill::Bill(const std::string& user_name, const std::string& address, const std::string& CC)
	: m_user_name(user_name)
	, m_address(address)
	, m_CC(CC)

{ }

////////////////////////////////////////
// GETTERS
////////////////////////////////////////
std::string LIBRARY::Bill::get_user_name() const
{
	return m_user_name;
}

std::string LIBRARY::Bill::get_address() const
{
	return m_address;
}

// return the quantity available
std::string LIBRARY::Bill::get_CC() const
{
	return m_CC;
}


////////////////////////////////////////
// SETTERS
////////////////////////////////////////


void LIBRARY::Bill::print() const
{
	std::cout << "\n\t\t\t User Name: " << m_user_name;
	std::cout << "\n\t\t\t User Address: " << m_address;
	std::cout << "\n\t\t\t User Credit Card: " << m_CC;
	std::cout << std::endl;
}