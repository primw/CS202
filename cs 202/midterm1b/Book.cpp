// Prim Wandeevong // CS 202 - Book.cpp // 10-16-19 //
#include <iostream>
#include <cstring>
#include "Book.h"
#include "proj6.h"


using namespace std;

int Book::s_idgen = 0;


//Default Constructor
Book::Book() : m_id(s_idgen++)
{
    setTitle(DEFAULT_TITLE);
    setIsbn(DEFAULT_ISBN);
    free();
}


//Parameterized Constructor
Book::Book(const char* title, const int* isbn, const char* renter) : m_id(s_idgen++)
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
Book& Book::operator=(const Book& other)
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
void Book::setTitle(const char* title) {strcpy(m_title, title);}
void Book::setAvailable(const bool available) {m_available = available;}
void Book::setRenter(const char* renter) {strcpy(m_renter, renter);}
void Book::setIsbn(const int* isbn)
{
    intcpy(m_isbn, isbn);
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
    if (!strcmp(m_title, DEFAULT_TITLE || !intcmp(m_isbn, DEFAULT_ISBN)))
    {
        return false;
    }

    return true;
}


//Operator+ Method
bool Book::operator+(const char* renter)
{
    if(!m_available || !strcmp(renter, DEFAULT_RENTER))
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
ostream& operator<<(ostream& os, const Book& other)
{
    os << other.m_title << " (" << other.m_id << ") ";
    intprint(os, other.m_isbn);

    if (other.m_available)
    {
        os << "Free to rent!";
    }

    else
    {
        os << "Rented to: " << other.m_renter;
    }

    return os;
}
    