// Prim Wandeevong // CS 202 Project 7 - MyString.h // 10-30-19 //
#ifndef MyStringH
#define MyStringH

#include <iostream>
using namespace std;

class MyString
{
    public:
        MyString();
        MyString(const char* str);
        MyString(const MyString& other);
        ~MyString();

        size_t size() const;
        size_t length() const;
        const char* c_str() const;

        bool operator== (const MyString& other) const;
        MyString& operator= (const MyString& other);
        MyString operator+ (const MyString& other) const;
        char& operator[] (size_t index);
        const char& operator[] (size_t index) const;

        friend ostream& operator<< (ostream& os, const MyString& myStr);

    private:
        void buffer_deallocate();
        void buffer_allocate(size_t size);
        char* m_buffer;
        size_t m_size;

};

#endif
