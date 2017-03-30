//Library System
//Caleb Heidecker
#include <iostream>
#include <string>
#include <sstream>		// for stringstream
#include <vector>		// for vector container
#include "Book.h"
#include "Bill.h"
/*
#include "Library.h"
#include "User.h"
*/

////////////////////////////////////////
//Main.cpp
////////////////////////////////////////


// this should be a std::map<ISBN,Book>
typedef std::vector<LIBRARY::Book> BookContainer_t;
typedef std::vector<LIBRARY::Bill> UserContainer_t;

// read an entire line of input
std::string	getStringInput(const std::string& prompt = "")
{
	if (!prompt.empty())
	{
		std::cout << prompt;
	}

	std::string s;
	std::getline(std::cin, s);

	if ((!prompt.empty()) && ('\n' != prompt[prompt.size() - 1]))
	{
		std::cout << std::endl;
	}

	return s;
}

// read an entire line, but only the first int
int		getIntegerInput(const std::string& prompt = "")
{
	std::istringstream is(getStringInput(prompt));
	int i;
	is >> i;
	return i;
}

// read an entire line, but only the first double
double	 getDoubleInput(const std::string& prompt = "")
{
	std::istringstream is(getStringInput(prompt));
	double d;
	is >> d;
	return d;
}

// read an entire line, but only the first char, convert to bool
bool	getBoolInput(const std::string& prompt = "")
{
	std::istringstream is(getStringInput(prompt));
	char c;
	is >> c;
	c = tolower(c);// or c=std::tolower(c);
	return (('t' == c) || ('y' == c) || ('1' == c));
}

void	displayMenu()
{
	std::cout << "\n\n\t\t\t LIBRARY MANAGMENT SYSTEM";
	std::cout << "\n\t\t\t Created By: Caleb Heidecker";
	std::cout << "\n\t\t\t 1. Add New Book";
	std::cout << "\n\t\t\t 2. Borrow Book";
	std::cout << "\n\t\t\t 3. Display Available Books to Borrow";
	std::cout << "\n\t\t\t 4. Delete Book";
	std::cout << "\n\t\t\t 5. Find Book";
	std::cout << "\n\t\t\t 6. Display All Books";
	std::cout << "\n\t\t\t 7. Purchase Book";
	std::cout << "\n\t\t\t 8. Quit" << std::endl;
}

void	add_book(BookContainer_t& books)
{
	do
	{
		const std::string	ISSBN = getStringInput("Enter Book ISSBN: ");
		const std::string	title = getStringInput("Enter Book Title: ");
		const std::string	author_name = getStringInput("Enter Author's Name: ");
		const double		price = getDoubleInput("Enter Book Price: ");
		const size_t		quantity = getIntegerInput("Enter Book Quantity: ");
		LIBRARY::Book newBook(title, ISSBN, price, quantity, author_name);
		books.emplace_back(newBook);
	} while (getBoolInput("Do you wish to continue (Y/N) ?"));
}

void	add_user(UserContainer_t& users)//@todo add XXX code and expiration date
{
		const std::string	user_name = getStringInput("Enter Name: ");
		const std::string	address = getStringInput("Enter Address: ");
		const std::string	CC = getStringInput("Enter Credit Card Number: ");
		LIBRARY::Bill newUser(user_name, address, CC);
		users.emplace_back(newUser);
}

bool	find_book(const BookContainer_t& books, const std::string& ISSBN, size_t& index)
{
	bool found(false);
	for (size_t i = 0; i < books.size(); ++i)
	{
		if (ISSBN == books[i].get_ISSBN())
		{
			found = true;
			index = i;
			break;
		}
	}
	if (found)
	{
		std::cout << "Book with ISSBN " << ISSBN << " was found at index " << index << ":" << std::endl;
	}
	else
	{
		std::cerr << "Book with ISSBN " << ISSBN << " was not found in our system" << std::endl;
	}
	return found;
}

int main()
{
	BookContainer_t books;
	UserContainer_t users;

	int choice(0);
	do
	{
		displayMenu();
		choice = getIntegerInput("\n\n\t\t\t Enter your choice HERE=> ");
		switch (choice)
		{
		case 1:
		{
			// add new book
			add_book(books);
			break;
		}
		case 2:
		{
			// borrow book
			const std::string ISSBN = getStringInput("Enter ISSBN no: ");
			size_t index;
			if (find_book(books, ISSBN, index))
			{
				if (books[index].set_borrowed())
				{
					std::cout << "The book " << books[index].get_title() << " is Borrowed Successfully: " << books[index].get_quantity() << " still available" << std::endl;
				}
				else
				{
					std::cerr << "The book " << books[index].get_title() << " cannot be borrowed because all have been borrowed" << std::endl;
				}
			}
			break;
		}
		case 3:
		{
			// display available books to borrow
			for (size_t i = 0; i < books.size(); ++i)
			{
				if (books[i].get_quantity() > 0)
				{
					books[i].print();
				}
			}
			break;
		}
		case 4:
		{
			// delete a book by its ISSBN
			const std::string ISSBN = getStringInput("Enter ISSBN no: ");
			size_t index;
			if (find_book(books, ISSBN, index))
			{
				books.erase(books.begin() + index);
			}
			break;
		}
		case 5:
		{
			// find a book by its ISSBN
			const std::string ISSBN = getStringInput("Enter ISSBN no: ");
			size_t index;
			if (find_book(books, ISSBN, index))
			{
				books[index].print();
			}
			break;
		}
		case 6:
		{
			// display all books
			std::cout << "There are " << books.size() << " book titles in the library" << std::endl;
			for (size_t i = 0; i < books.size(); ++i)
			{
				books[i].print();
			}
			std::cout << std::endl;
			break;
		}

		case 7:
		{
			// buy book
			add_user(users);
			const std::string ISSBN = getStringInput("Enter ISSBN no: ");
			size_t index;
			if (find_book(books, ISSBN, index))
			{
				if (books[index].set_borrowed())
				{
					std::cout << "The book " << books[index].get_title() << " was Bought Successfully for: " << books[index].get_price() << std::endl;
					std::cout << books[index].get_quantity() << " still available" << std::endl;
				}
				else
				{
					std::cerr << "The book " << books[index].get_title() << " cannot be purchased because all copies have been borrowed or purchased" << std::endl;
				}
			}
			system("pause");
			break;
		}

		// @todo need a case to return a borrowed book

		case 8:
		{
			// quit
			break;
		}
		default:
		{
			std::cerr << "\n\t\t\t Please Try Again...." << std::endl;
			break;
		}
		};
	} while (7 != choice);

	return 0;
}
