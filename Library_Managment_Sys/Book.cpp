////////////////////////////////////////
//Book.cpp
////////////////////////////////////////

#include<iostream>
#include <string>
#include "Book.h"

////////////////////////////////////////
// Non-default Ctor
////////////////////////////////////////
LIBRARY::Book::Book(const std::string& title, const std::string& ISSBN, const double price, const int totalQuantity, const std::string& author_name)
	: m_title(title)
	, m_ISSBN(ISSBN)
	, m_price(price)
	, m_quantityAvailable(totalQuantity)
	, m_author_name(author_name)
	, m_quantityBorrowed(0)
{ }

////////////////////////////////////////
// GETTERS
////////////////////////////////////////
std::string LIBRARY::Book::get_title() const
{
	return m_title;
}

std::string LIBRARY::Book::get_ISSBN() const
{
	return m_ISSBN;
}

double LIBRARY::Book::get_price() const
{
	return m_price;
}

// return the quantity available
size_t LIBRARY::Book::get_quantity() const
{
	return m_quantityAvailable;
}

std::string LIBRARY::Book::get_author_name() const
{
	return m_author_name;
}

// return the quantity borrowed
size_t LIBRARY::Book::get_borrowed() const
{
	return m_quantityBorrowed;
}


////////////////////////////////////////
// SETTERS
////////////////////////////////////////
void LIBRARY::Book::set_price(const double newPrice)
{
	m_price = newPrice;
}


// add some more available copies of the book
void LIBRARY::Book::add_quantity(const size_t additionalQuantity)
{
	m_quantityAvailable += additionalQuantity;
}

// borrow some of the copies
bool LIBRARY::Book::set_borrowed(const size_t quantityToBorrow)
{
	if (m_quantityAvailable >= quantityToBorrow)
	{
		// there are enough to borrow
		m_quantityAvailable -= quantityToBorrow;
		m_quantityBorrowed += quantityToBorrow;
		return true;
	}
	// not enough available to borrow the specified quantity
	return false;
}

void LIBRARY::Book::print() const
{
	std::cout << "\n\t\t\t Book Title: " << m_title;
	std::cout << "\n\t\t\t Book ISSBN: " << m_ISSBN;
	std::cout << "\n\t\t\t Book Author: " << m_author_name;
	std::cout << "\n\t\t\t Book price: " << m_price;
	std::cout << "\n\t\t\t Book quantity: " << m_quantityAvailable;
	std::cout << "\n\t\t\t Book borrowed: " << m_quantityBorrowed;
	std::cout << std::endl;
}