////////////////////////////////////////
// Book.h
////////////////////////////////////////

#ifndef BOOK_H
#define BOOK_H

#include <string>

namespace LIBRARY
{
	class Book
	{
	public:
		// default Ctor
		Book() = delete;		// default ctor should be deleted, since you cannot have a book without a title or author,
								// and since a book with default/empty values is useless and meaningless?

								// non-default Ctor
								// @note added 2nd arg ISSBN
		Book(const std::string& title, const std::string& ISSBN, const double price, const int totalQuantity, const std::string& author_name);

		// getters
		std::string get_title() const;
		std::string	get_ISSBN() const;
		double		get_price() const;
		size_t		get_quantity() const;
		size_t		get_borrowed() const;
		std::string	get_author_name() const;

		// setters
		void set_price(const double newPrice);
		void add_quantity(const size_t newQuantity);
		bool set_borrowed(const size_t borrowedQuantity = 1);

		// print
		void print() const;

	private:
		std::string		m_title;
		std::string		m_ISSBN;
		double			m_price;
		size_t			m_quantityAvailable;	// totalQuantity = m_quantityAvailable + m_quantityBorrowed
		std::string		m_author_name;
		size_t			m_quantityBorrowed;
	};
}

#endif

