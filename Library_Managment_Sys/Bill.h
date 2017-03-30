#ifndef BILL_H
#define BILL_H

#include <string>

namespace LIBRARY
{
	class Bill
	{
	public:
		// default Ctor
		Bill() = delete;		// default ctor should be deleted, since you cannot have a book without a title or author,
								// and since a book with default/empty values is useless and meaningless?

								// non-default Ctor
		Bill(const std::string& user_name, const std::string& address, const std::string& CC);

		// getters
		std::string get_address() const;
		std::string	get_CC() const;
		std::string	get_user_name() const;

		// setters
		//Handled by book.h

		// print
		void print() const;

	private:
		std::string		m_address;
		std::string		m_CC;
		std::string		m_user_name;
	};
}

#endif

