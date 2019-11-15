// Prim Wandeevong // CS 202 Project 7 - MyString.cpp // 10-30-19 //
#include <iostream>
#include <cstring>
#include "MyString.h"
using namespace std;

//Default Constructor
MyString::MyString()
{
    buffer_allocate(0);
}


//Parameterized Constructor
MyString::MyString(const char* str)
{
    size_t size = strlen(str);
    
    try
    {
        buffer_allocate(size);
        
        for (int i = 0; i < size; i++)
        {
            (*this)[i] =  str[i];
        }
    }

    catch (const bad_alloc& e)
    {
        cerr << e.what() << endl;
        buffer_deallocate();
    }
}


//Copy Constructor
MyString::MyString(const MyString& other)
{
    try
    {
        buffer_allocate(other.size());

        for (int i = 0; i < other.size(); i++)
        {
            (*this)[i] = other[i];
        }
    }

    catch (const bad_alloc& e)
    {
        cerr << e.what() << endl;
        buffer_deallocate();
    }
}


//Destructor
MyString::~MyString()
{
    this->buffer_deallocate();
}


//Other Methods
size_t MyString::size() const {return m_size;}
size_t MyString::length() const {return m_size-1;}
const char* MyString::c_str() const {return m_buffer;}


//==Operator
bool MyString::operator== (const MyString& other) const
{
    for (int i = 0; other[i] && (other[i] == (*this)[i]); i++)
    
    if (other[i] - (*this)[i])
    {
        return false;
    }

    else
    {
        return true;
    }
    
}


//=Operator
MyString& MyString::operator= (const MyString& other)
{
    this->buffer_deallocate();

    try
    {
        this->buffer_allocate(other.size());

        for (int i = 0; i < other.size(); i++)
        {
            (*this)[i] = other[i];
        }
    }

    catch (const bad_alloc& e)
    {
        cerr << e.what() << endl;
        this->buffer_deallocate();
    }
    return *this;
}


//+Operator
MyString MyString::operator+ (const MyString& other) const
{
    size_t total_size = other.size() + size();

    char* cc_buffer;

    try
    {
        cc_buffer = new char [total_size];

        int i = 0;

        for (; i < size(); i++)
        {
            cc_buffer[i] = (*this)[i];
        }

        for(; i < total_size; i++)
        {
            cc_buffer[i] = other[i-size()];
        }
    }

    catch (const bad_alloc& e)
    {
        cerr << e.what() << endl;
    }
    return MyString(cc_buffer);
}


//[]Operator
char & MyString::operator[] (size_t index) {return m_buffer[index];}


//Const []Operator
const char & MyString::operator[] (size_t index) const {return m_buffer[index];}


//Friend Ostream
ostream& operator<< (ostream& os, const MyString& str)
{
    os << str.m_buffer;
    return os;
}


//Buffer Deallocate Method
void MyString::buffer_deallocate()
{
    delete[] m_buffer;
    m_buffer = NULL;
    m_size = 0;
}


//Buffer Allocate Method
void MyString::buffer_allocate(size_t size)
{
    try
    {
        m_size = size;
        m_buffer = new char[size];
    }
    catch(const exception& e)
    {
        std::cerr << e.what() << '\n';
        this->buffer_deallocate();
    }
}
