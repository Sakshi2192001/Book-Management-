#include<iostream>
#include "database.h"
#include "Books.h"


void Book::addbook() {
	Book b2;
	cout << "Enter Name Of The Book: " << endl;
	cin >> b2.bookname;
	cout << "Enter Name Of The Author: " << endl;
	cin >> b2.authorname;
	cout << "Enter The Genre Of The Book: " << endl;
	cin >> b2.genre;
	cout << "Enter The Year Of Publication Of The Book: " << endl;
	cin >> b2.publicationyear;

	mydatabase mydata;
	bool status = mydata.add_to_storage(b2);
	if (status == 0) {
		cout << "Book Added Successfully!";
	}
	else {
		cout << "Try again!";
	}

	mydata.~mydatabase();

};

void Book::find_by_bookname() {
	Book b3;
	cout << "Enter Bookname: " << endl;
	cin >> b3.bookname;
	mydatabase mydata;
	bool status = mydata.find_in_storage_usingname(b3);
	if (status == 0) {
		cout << "Book Not Found ." << endl;
	}
	mydata.~mydatabase();
};

void Book::find_by_authorname() {
	Book b4;
	cout << "Enter Author Name: " << endl;
	cin >> b4.authorname;
	mydatabase mydata;
	bool status = mydata.find_in_storage_usingauthor(b4);
	if (status == 0) {
		cout << "Book Not Found By This Author." << endl;
	}
	mydata.~mydatabase();
};

void Book::find_by_genre() {
	Book b5;
	cout << "Enter Genre: " << endl;
	cin >> b5.genre;
	mydatabase mydata;
	bool status = mydata.find_in_storage_using_genre(b5);
	if (status == 0) {
		cout << "Book Not Found By This Author." << endl;
	}
	mydata.~mydatabase();
};

void Book::update_by_bookname() {
	Book b6;
	cout << "Enter Author Of The Book: " << endl;
	cin >> b6.authorname;
	cout << "Enter Genre Of The Book: " << endl;
	cin >> b6.genre;
	cout << "Enter Publication Year Of The Book: " << endl;
	cin >> b6.publicationyear;
	string bname;
	cout << "Enter New Book Name: " << endl;
	cin >> bname;
	mydatabase mydata;
	mydata.update_in_storage_by_name(b6, bname);
	mydata.~mydatabase();
};

void Book::update_by_authorname() {
	Book b7;
	cout << "Enter Name Of The Book: " << endl;
	cin >> b7.bookname;
	cout << "Enter Genre Of The Book: " << endl;
	cin >> b7.genre;
	cout << "Enter Publication Year Of The Book: " << endl;
	cin >> b7.publicationyear;
	string aname;
	cout << "Enter Correct Author Name: " << endl;
	cin >> aname;
	mydatabase mydata;
	mydata.update_in_storage_by_author(b7, aname);
	mydata.~mydatabase();
};

void Book::update_by_genre() {
	Book b8;
	cout << "Enter Name Of The Book: " << endl;
	cin >> b8.bookname;
	cout << "Enter Author Of The Book: " << endl;
	cin >> b8.authorname;
	cout << "Enter Publication Year Of The Book: " << endl;
	cin >> b8.publicationyear;
	string gname;
	cout << "Enter Correct Genre Of The Book: " << endl;
	cin >> gname;
	mydatabase mydata;
	mydata.update_in_storage_by_genre(b8, gname);
	mydata.~mydatabase();
};

void Book::update_by_publicationyear() {
	Book b9;
	cout << "Enter Name Of The Book: " << endl;
	cin >> b9.bookname;
	cout << "Enter Author Of The Book: " << endl;
	cin >> b9.authorname;
	cout << "Enter Genre Of The Book: " << endl;
	cin >> b9.genre;
	int p;
	cout << "Enter Correct Publication Year Of The Book: " << endl;
	cin >> p;
	mydatabase mydata;
	mydata.update_in_storage_by_year(b9, p);
	mydata.~mydatabase();
};

void Book::delete_book() {
	Book b10;
	cout << "Enter Name Of The Book You Want To Delete: " << endl;
	cin >> b10.bookname;
	cout << "Enter Author Of The Book You Want To Delete: " << endl;
	cin >> b10.authorname;
	cout << "Enter Genre Of The Book You Want To Delete: " << endl;
	cin >> b10.genre;
	cout << "Enter Publication Year Of The Book You Want To Delete: " << endl;
	cin >> b10.publicationyear;
	mydatabase mydata;
	mydata.delete_book_from_storage(b10);
	mydata.~mydatabase();
};

void Book::view_all() {
	mydatabase mydata;
	mydata.view_from_storage();

};