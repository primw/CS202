// Prim Wandeevong // CS 202 - Library.cpp // 10-17-19 //
#include <iostream>
#include <cstring>
#include "Book.h"
#include "Library.h"
using namespace std;

const char* Library::getName() const {return m_name;}
void Library::setName(const char* name) {strcpy(m_name, name);}(


//Find Open Spot Method
Book* Library::findOpenSpot()
{
    Book* inventory_ptr = m_inventory;

    while (inventory_ptr->valid())
    {
        if (!inventory_ptr->valid())
        {
            return inventory_ptr;
        }

        inventory_ptr++;
    }
    return NULL;
}


//Operator[] - Find spot with same title
Book* Library::operator[](const char* title)
{
    Book* inventory_ptr = m_inventory;

    while (!strcmp(inventory_ptr->getTitle(), title))
    {
        if (strcmp(inventory_ptr->getTitle(), title))
        {
            return inventory_ptr;
        }

        inventory_ptr++;
    }
    return NULL;
}


//Operator[] - Return index
Book& Library::operator[](int index) {return m_inventory[index];}


//Rent Book Method
bool Library::rentBook(const Book& myBook)
{
    if (myBook.valid())
    {
        Book* openBook_ptr = findOpenSpot();

        if (openBook_ptr)
        {
            *openBook_ptr = myBook;
            return true;
        }
    }
    return false;
}


//Operator<< Method
ostream& operator<< (ostream& os, const Library& lib)
{
    Book* inventory_ptr = lib.m_inventory;

    for (int i = 0; i < LIBRARY; i++)
    {
        if (inventory_ptr->valid())
        {
            os << "Index: " << i << " Book:" << *inventory_ptr << endl;
        }
    }
    return os;
}


//Paramterized Constructor
Library::Library(const char* name)
{
    setName(name);
}