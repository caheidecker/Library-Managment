#include<iostream>
#include <string>
#include "Bill.h"

////////////////////////////////////////
// Non-default Ctor
////////////////////////////////////////
LIBRARY::Bill::Bill(const std::string& CC, const std::string securityNum, const std::string expirationDate)
	: m_CC(CC)
	, m_securityNum(securityNum)
	, m_expirationDate(expirationDate)

{ }

////////////////////////////////////////
// GETTERS
////////////////////////////////////////

// return the quantity available
std::string LIBRARY::Bill::get_CC() const
{
	return m_CC;
}
std::string LIBRARY::Bill::get_securityNum() const
{
	return m_securityNum;
}
std::string LIBRARY::Bill::get_expirationDate() const
{
	return m_expirationDate;
}

////////////////////////////////////////
// SETTERS
////////////////////////////////////////


void LIBRARY::Bill::print() const
{
	std::cout << "\n\t\t\t User Credit Card: " << m_CC;
	std::cout << "\n\t\t\t User CC Security Number: " << m_securityNum;
	std::cout << "\n\t\t\t User CC Expiration Date: " << m_expirationDate;
	std::cout << std::endl;
}