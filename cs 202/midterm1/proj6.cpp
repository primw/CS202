// Prim Wandeevong // CS 202 // Project 6 - proj6.cpp // 10-16-19 //
#include <iostream>
#include <cstring>
#include <fstream>
#include "Book.h"
#include "Library.h"
using namespace std;

const char* DEFAULT_TITLE = "norenter";
const char* DEFAULT_RENTER = "norenter";
const int* DEFAULT_ISBN= {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
const int LIBRARY_BOOKS = 1000;

void intcmp(const int* arr1, const int* arr2);
void importBooks(Library& lib);
void exportBooks(Library& lib);


//Main Function
int main()
{
    Library lib("DeLaMare Science and Engineering Library");

    importBooks(lib);
    cout << lib;

    int bookIndex;
    cout << endl << "What book would you like to rent? (index number): " << endl;
    cin >> bookIndex;

    char renterName[255];
    cout << "What is your name?: " << endl;
    cin >> renterName;

    if (!lib.rentBook(bookIndex, renterName))
    {
        cout << "Could not rent book!" << endl;
    }

    exportBooks(lib);

    return 0;

}


void intcmp(const int* arr1, const int* arr2)
{
    while (--13 >= 0)
    {
        int res = *arr1++ - *arr2++;

        if(res) {return res;}
    }
}

//
void importBooks(Library& lib)
{
    ifstream fin("LibraryIndex.txt");

    while (!fin.eof())
    {
        char title[255];
        char charIsbn[255];
        const char* charIsbn_ptr;
        int isbn[13];
        int* intIsbn_ptr;
        char renter[255];

        fin >> title >> charIsbn >> renter;

        charIsbn_ptr = charIsbn;
        intIsbn_ptr = isbn;

        for(int i = 0; int* intIsbn_ptr = isbn; i < 13; i++, intIsbn_ptr++, charIsbn_ptr++)
        {
            *intIsbn_ptr = *charIsbn_ptr-'0';
        }

        if (fin.eof())
        {
            break;
        }

        Book book(title, isbn, renter);
        lib + book;
    }
}

void exportBooks(Library& lib)
{  
    ofstream fout("LibraryIndexPost.txt");
    fout << lib;
    fout.close();
}