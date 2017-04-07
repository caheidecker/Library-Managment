/*This class would:
1) hold the array of books 'BookContainer_t book's instead of 'main.cpp'
2) have a method to add to the array of books given a filename argument.
3) move the add_book, and find_book methods from 'main' into this class
4) Add a "delete_book' method (essentially calling book_find and erase() insteadof doing it in main
5) add a display_all_books method (move the code from main into its own method in LibraryManager)

In other words, move all the book code (the "domain" knowledge) into its own class... out of 'main'.
Main will then just create an instance of the LibraryManager class and handle the User Interface.

In the book class, create 2 new methods:
1) std::string  toCSV() const
    This method just writes out each piece of book data, separated by a comma ','

2) static Book fromCSV(const std::string bookCSV) 
    This method creates a new book from the same kind of csv string
*/

#ifndef LIBRARYMANAGER_H// this is class Library
#define LIBRARYMANAGER_H

#include <iostream>		// for general I/O
#include <fstream>		// for reading and writing the list of books to a file
#include <string>
#include <vector>		// for the container of books in memory
#include "Book.h"

namespace LIBRARY
{
	class Manager
	{
	public:
		/**
		* default ctor
		* deleted because we require the user to provide the name of the file holding all the books
		*/
		Manager() = delete;

		/**
		* Non-default ctor
		* Read a file of book info into the array of books
		*
		* @param[in]	filename		the name of the file that always holds the books, one book per line, CSV format
		*/
		Manager(const std::string& filename)
			: m_filename(filename)
		{
			readBookFile();
		}

		/**
		* Virtual dtor
		* Rewrite the file with all the updated, current information
		*/
		virtual ~Manager()
		{
			writeBookFile();
		}


		/**
		* Print all the books to stdout, nicely formatted
		*/
		void print() const;

		/**
		* Add a new book to the library
		* If the book does not exist at all , then add it
		*  (quantity borrowed should be zero in the new book)
		*
		* If the book already exists, then simply increment the number of copies by its quantity available
		*  (quantity borrowed should be zero in the new book)
		*
		* @param[in]	newBook		the new book to add
		*
		* @return true on success, false otherwise
		*/
		bool add_book(const LIBRARY::Book&  newBook);


		/**
		* Find a book in the library, but don't borrow it
		*
		* @param[in]	ISSBN			the ISSBN of the book to search for
		* @param[out]	foundBook		the book if found
		*
		* @return true if book found, false otherwise
		*/
		bool find_book(const std::string& ISSBN, LIBRARY::Book& foundBook) const;


		/**
		* Find and erase a book from the library
		*
		* @param[in]	ISSBN			the ISSBN of the book to search for
		*
		* @return true if book found and erased, false otherwise
		*/
		bool erase_book(const std::string& ISSBN);

		/**
		* Borrow a book by decrementing quantity available and incrementing quantity borrowed
		*
		* @param[in]	ISSBN		the ISSBN of the book to search for
		* @param[out]	foundBook	the book if found and copies available to check out
		*
		* @return true if book found and there is at least one available and borrowed, false otherwise
		*/
		bool borrow_book(const std::string& ISSBN);

		/**
		* Return a borrowed book by incrementing quantity_available and decrementing quantity borrowed
		*
		* @param[in]	ISSBN		the ISSBN of the book to return to the library
		*
		* @return true if book found and returned, false otherwise
		*/
		bool return_book(const std::string& ISSBN);

		// class private methods
	private:

		/**
		* Read books from a file called m_filename, and add them to the array of books by calling add_book() above
		* Read one entire line from the file into a string, then call Book::fromCSV(string), the call add_book
		* Report all errors
		*/
		void readBookFile();

		/**
		* Write out m_books to file, one book per line, fields separated by ',' (i.e., CSV format)
		* Walk the array of books. For each book, call its toCSV to get a string and write the string to file
		*/
		void writeBookFile() const;


		// class private data
	private:
		// this should be a std::map<ISBN,Book> but we can use that for now
		typedef std::vector<LIBRARY::Book> BookContainer_t;

		std::string			m_filename;		///< the name of the file that always holds the books
		BookContainer_t		m_books;		///< all the books
	};
}

#endif

