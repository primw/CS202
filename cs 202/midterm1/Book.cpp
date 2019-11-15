// Prim Wandeevong // CS 202 - Book.cpp // 10-16-19 //
#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;

int Book::s_idgen = 0;


//Default Constructor
Book::Book() : m_id(s_idgen++)
{
    setTitle("norenter");
    setIsbn(DEFAULT_ISBN);
    free();
}


//Parameterized Constructor
Book::Book(char* title = DEFAULT_TITLE, int* isbn = DEFAULT_ISBN, char* renter = DEFAULT_RENTER) : m_id(s_idgen++)
{
    setTitle(title);
    setIsbn(isbn);
    setRenter(renter);
    free();

    if(strcmp(renter, DEFAULT_RENTER))
    {
        this->operator+(renter);
    }
}

//Copy Constructor
Book::Book(const Book& other) : m_id(s_idgen++)
{
    setTitle(other.m_title);
    setIsbn(other.m_isbn);
    free(); 
}

//Destructor
Book::~Book()
{
    //Nothing special xd
}


//Book operator=
Book&::Book operator= (const Book& other)
{
    if (this != &other)
    {
        setTitle(other.m_title);
        setIsbn(other.m_isbn);
       
        if (other.m_available)
        {
            free();
        }
        else
        {
            this->operator+(other.m_renter);
        }
    }
    return *this;   
}



//Setter Methods
void Book::setTitle(char* title) {strcpy(m_title, title);}
void Book::setAvailable(bool available) {m_available = available;}
void Book::setRenter(char* renter) {strcpy(m_renter, renter);}
void Book::setIsbn(int* isbn)
{
    for(int i = 0; i < 13; i++)
    {
       *m_isbn = *isbn;

       m_isbn++;
       isbn++;
    }
}


//Getter Methods
const int Book::getId() const {return m_id;}
const char* Book::getTitle() const {return m_title;}
const bool Book::getAvailable() const {return m_available;}
const char* Book::getRenter() const {return m_renter;}
const int Book::getIdgen() const {return s_idgen;}
const int* Book::getIsbn() const {return m_isbn;}


//Check Valid Method 
bool Book::valid()
{
    if(!strcmp(m_title, DEFAULT_TITLE || !intcmp(m_isbn, DEFAULT_ISBN))
    {
        return false;
    }

    return true;
}


//Operator+ Method
bool Book::operator+(const char* renter)
{
    if(!m_available || !strcomp(renter, DEFAULT_RENTER))
    {
        return false;
    }

    else 
    {
        strcpy(m_renter, renter);
        setAvailable(false);
    }
}


//Free Method
void Book::free()
{
    setAvailable(true);
}


//Operator<< Method
friend ostream& operator<<(ostream& os, const Book& myBook)
{
    if(this != &other)
    {
        setTitle(other.m_title);
        setIsbn(other.m_isbn);

        if (other.m_available)
        {
            free();
        }
        else
        {
            this->operator+(other.m_renter);
        }
    }
    return *this;
}
