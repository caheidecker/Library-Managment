#ifndef USER_H
#define USER_H

#include <string>

namespace LIBRARY
{
	class User
	{
	public:
		// default Ctor
		User() = delete;

		// non-default Ctor
		User(const std::string& user_name, const std::string& address, const std::string& phoneNum, const std::string& DOB);

		// getters
		std::string get_address() const;
		std::string	get_user_name() const;
		std::string get_phoneNum() const;
		std::string get_DOB() const;
		// setters
		//Handled by book.h

		// print
		void print() const;

	private:
		std::string		m_address;
		std::string		m_user_name;
		std::string		m_securityNum;
		std::string		m_phoneNum;
		std::string		m_DOB;
	};
}
#endif