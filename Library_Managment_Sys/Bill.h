#ifndef BILL_H
#define BILL_H

#include <string>

namespace LIBRARY
{
	class Bill
	{
	public:
		// default Ctor
		Bill() = delete;	

								// non-default Ctor
		Bill(const std::string& CC, const std::string securityNum, const std::string expirationDate);

		// getters
		std::string	get_CC() const;
		std::string get_securityNum() const;
		std::string get_expirationDate() const;

		// setters
		//Handled by book.h

		// print
		void print() const;

	private:
		std::string		m_CC;
		std::string		m_securityNum;
		std::string		m_expirationDate;
	};
}
#endif

