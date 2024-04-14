#pragma once
#include<iostream>
using namespace std;

class Book {
public:
	string bookname;
	string authorname;
	string genre;
	int publicationyear;
	void addbook();
	void find_by_bookname();
	void find_by_authorname();
	void find_by_genre();
	void update_by_bookname();
	void update_by_authorname();
	void update_by_genre();
	void update_by_publicationyear();
	void delete_book();
	void view_all();

};
