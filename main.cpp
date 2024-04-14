#include<stdlib.h>
#include<iostream>
#include "Books.h"
using namespace std;

int main()
{
   
    Book b1;
    cout << "FIND YOUR FAVOURITES IN BOOK STORAGE: " << endl<<endl;
    cout << "Press 1 To Insert Book In The Storage: " << endl;
    cout << "Press 2 To Find Book In The Storage: " << endl;
    cout << "Press 3 To Update Book Data In The Storage: " << endl;
    cout << "Press 4 To Delete Book From The Storage: " << endl;
    cout << "Press 5 To View All Books From The Storage: " << endl;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        b1.addbook();
        break;
    case 2:
        cout << "Press 1 To Find Book By Bookname: " << endl;
        cout << "Press 2 To Find Book By Authorname: " << endl;
        cout << "Press 3 To Find Book By Genre: " << endl;
        int f;
        cin >> f;
        switch (f)
        {
        case 1:
            b1.find_by_bookname();
            break;
        case 2:
            b1.find_by_authorname();
            break;
        case 3:
            b1.find_by_genre();
            break;
        default:
            cout << "TRY AGAIN!" << endl;
            break;
        }
        break;
    case 3:
        cout << "Press 1 To Update Book By Bookname: " << endl;
        cout << "Press 2 To Update Book By Authorname: " << endl;
        cout << "Press 3 To Update Book By Genre: " << endl;
        cout << "Press 4 To Update Book By Publicationyear: " << endl;
        int u;
        cin >> u;
        switch (u)
        {
        case 1:
            b1.update_by_bookname();
            break;
        case 2:
            b1.update_by_authorname();
            break;
        case 3:
            b1.update_by_genre();
            break;
        case 4:
            b1.update_by_publicationyear();
            break;
        default:
            cout << "TRY AGAIN!" << endl;
            break;
        }
        break;
    case 4:
        b1.delete_book();
        break;
    case 5:
        b1.view_all();
        break;
    default:
        cout << "TRY AGAIN!" << endl;
        break;
    }
    return 0;
}