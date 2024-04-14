#pragma once
#include <stdlib.h>
#include <iostream>
#include "Books.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
using namespace std;

class mydatabase {
private:
	const string server = "";
	const string username = "";
	const string password = "";
	sql::Connection* con;
public:
	mydatabase();
	~mydatabase();
	bool add_to_storage(Book b);
	bool find_in_storage_usingname(Book b);
	bool find_in_storage_usingauthor(Book b);
	bool find_in_storage_using_genre(Book b);
	void update_in_storage_by_name(Book b, string x);
	void update_in_storage_by_author(Book b, string x);
	void update_in_storage_by_genre(Book b, string x);
	void update_in_storage_by_year(Book b, int x);
	void delete_book_from_storage(Book b);
	void view_from_storage();
};