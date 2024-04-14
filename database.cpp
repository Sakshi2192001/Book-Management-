#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include "database.h"
#include "Books.h"
using namespace std;


mydatabase::mydatabase() {
	sql::Driver* driver;
	driver = get_driver_instance();
	con = driver->connect(server, username, password);
	cout << "connection created"<<endl;

	con->setSchema("BOOKS");
}

mydatabase::~mydatabase() {
	delete con;
}

bool mydatabase::add_to_storage(Book b2) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("INSERT INTO BOOK_STORAGE(bookname,authorname,genre,publicationyear) VALUES(?,?,?,?)");
	pstmt->setString(1, b2.bookname);
	pstmt->setString(2, b2.authorname);
	pstmt->setString(3, b2.genre);
	pstmt->setInt(4, b2.publicationyear);
	status = pstmt->execute();
	return status;
}

bool mydatabase::find_in_storage_usingname(Book b) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM BOOK_STORAGE");
	status = pstmt->execute();
	if (status) {
		sql::ResultSet* res = pstmt->getResultSet();
		if (res) {
			while (res->next()) {
				string bname = res->getString("bookname");
				if (bname == b.bookname) {
					string aname = res->getString("authorname");
					string gname = res->getString("genre");
					int p = res->getInt("publicationyear");
					//cout << "BOOK NAME:- " << bname << " " << "AUTHOR NAME:- " << aname << " " << "GENRE:- " << gname << " " << "PUBLICATION YEAR OF BOOK:- " << " " << p << endl;
					cout << "BOOK NAME:- " << bname << " " << "\n" << "AUTHOR NAME : -" << aname << " " << "\n" << "GENRE : -" << gname << " " << "\n" << "PUBLICATION YEAR OF BOOK : -" << " " << p << endl << endl;
				}
			}
		}
	}
	return status;
}

bool mydatabase::find_in_storage_usingauthor(Book b) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM BOOK_STORAGE");
	status = pstmt->execute();
	if (status) {
		sql::ResultSet* res = pstmt->getResultSet();
		if (res) {
			while (res->next()) {
					string aname = res->getString("authorname");
				if (aname == b.authorname) {
				string bname = res->getString("bookname");
					string gname = res->getString("genre");
					int p = res->getInt("publicationyear");
					//cout << "BOOK NAME:- " << bname << " " << "AUTHOR NAME:- " << aname << " " << "GENRE:- " << gname << " " << "PUBLICATION YEAR OF BOOK:- " << " " << p << endl;
					cout << "BOOK NAME:- " << bname << " " << "\n" << "AUTHOR NAME : -" << aname << " " << "\n" << "GENRE : -" << gname << " " << "\n" << "PUBLICATION YEAR OF BOOK : -" << " " << p << endl << endl;
				}
			}
		}
	}
	return status;
}

bool mydatabase::find_in_storage_using_genre(Book b) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM BOOK_STORAGE");
	status = pstmt->execute();
	if (status) {
		sql::ResultSet* res = pstmt->getResultSet();
		if (res) {
			while (res->next()) {
				string gname = res->getString("genre");
				if (gname == b.genre) {
					string bname = res->getString("bookname");
					string aname = res->getString("authorname");
					int p = res->getInt("publicationyear");
					//cout << "BOOK NAME:- " << bname << " " << "AUTHOR NAME:- " << aname << " " << "GENRE:- " << gname << " " << "PUBLICATION YEAR OF BOOK:- " << " " << p << endl;
					cout << "BOOK NAME:- " << bname << " " << "\n" << "AUTHOR NAME : -" << aname << " " << "\n" << "GENRE : -" << gname << " " << "\n" << "PUBLICATION YEAR OF BOOK : -" << " " << p << endl << endl;
				}
			}
		}
	}
	return status;
}

void mydatabase::update_in_storage_by_name(Book b, string x) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("UPDATE BOOK_STORAGE SET bookname=? WHERE authorname=? AND genre=? AND publicationyear=? ");
	pstmt->setString(1, x);
	pstmt->setString(2, b.authorname);
	pstmt->setString(3, b.genre);
	pstmt->setInt(4, b.publicationyear);
	status = pstmt->execute();
	if (status==0) {
		cout << "Book updated." << endl;
	}
	else {
		cout << "Book not updated." << endl;
	}
}


void mydatabase::update_in_storage_by_author(Book b, string x) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("UPDATE BOOK_STORAGE SET authorname=? WHERE bookname=? AND genre=? AND publicationyear=? ");
	pstmt->setString(1, x);
	pstmt->setString(2, b.bookname);
	pstmt->setString(3, b.genre);
	pstmt->setInt(4, b.publicationyear);
	status = pstmt->execute();
	if (status == 0) {
		cout << "Book updated." << endl;
	}
	else {
		cout << "Book not updated." << endl;
	}
}

void mydatabase::update_in_storage_by_genre(Book b, string x) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("UPDATE BOOK_STORAGE SET genre=? WHERE bookname=? AND authorname=? AND publicationyear=? ");
	pstmt->setString(1, x);
	pstmt->setString(2, b.bookname);
	pstmt->setString(3, b.authorname);
	pstmt->setInt(4, b.publicationyear);
	status = pstmt->execute();
	if (status == 0) {
		cout << "Book updated." << endl;
	}
	else {
		cout << "Book not updated." << endl;
	}
}

void mydatabase::update_in_storage_by_year(Book b, int x) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("UPDATE BOOK_STORAGE SET publicationyear=? WHERE bookname=? AND authorname=? AND genre=? ");
	pstmt->setInt(1, x);
	pstmt->setString(2, b.bookname);
	pstmt->setString(3, b.authorname);
	pstmt->setString(4, b.genre);
	status = pstmt->execute();
	if (status == 0) {
		cout << "Book updated." << endl;
	}
	else {
		cout << "Book not updated." << endl;
	}
}

void mydatabase::delete_book_from_storage(Book b) {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("DELETE FROM BOOK_STORAGE WHERE bookname=? AND authorname=? AND genre=? AND publicationyear=?");
	pstmt->setString(1, b.bookname);
	pstmt->setString(2, b.authorname);
	pstmt->setString(3, b.genre);
	pstmt->setInt(4, b.publicationyear);
	status = pstmt->execute();
	if (status == 0) {
		cout << "Book is deleted." << endl;
	}
	else {
		cout << "Book is not deleted." << endl;
	}

}

void mydatabase::view_from_storage() {
	bool status;
	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT * FROM BOOK_STORAGE");
	status = pstmt->execute();
	if (status) {
		sql::ResultSet* res = pstmt->getResultSet();
		if (res) {
			while (res->next()) {
				string aname = res->getString("authorname");
				string bname = res->getString("bookname");
				string gname = res->getString("genre");
				int p = res->getInt("publicationyear");
				cout << "BOOK NAME:- " << bname << " "<<"\n" << "AUTHOR NAME : -" << aname << " " <<"\n"<< "GENRE : -" << gname << " "<<"\n" << "PUBLICATION YEAR OF BOOK : -" << " " << p << endl<<endl;

				
			}
		}
	}
}
 
