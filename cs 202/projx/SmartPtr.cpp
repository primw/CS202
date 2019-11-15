// Prim Wandeevong // CS 202 - ProjectX // 11-1-19 //
#include <iostream>
#include "SmartPtr.h"
#include "DataType.h"
using namespace std;


//Default Constructor
SmartPtr::SmartPtr()
{
    m_ptr = new DataType;
    m_refcount = new size_t;
    *m_refcount = 1;
    cout << "SmartPtr Default Constructor for new allocation, RefCount = " << *m_refcount << endl;

}


//Parameterized Constructor
SmartPtr::SmartPtr(DataType* dtPtr)
{
    m_ptr = dtPtr;
    m_refcount = new size_t;
    *m_refcount = 0;

    if (m_ptr !=NULL)
    {
        *m_refcount++;
    }

    cout << "SmartPtr Parameterized Constructor from data pointer, RefCount = " << *m_refcount << endl;
}


//Copy Constructor
SmartPtr::SmartPtr(const SmartPtr& other)
{
    if (other.m_ptr) 
    {
        m_refcount = other.m_refcount;
        (*m_refcount)++;
    } 
    else 
    {
        m_refcount = new size_t;
        *m_refcount = 0;
    }

    m_ptr = other.m_ptr;


    cout << "SmartPtr Copy Constructor, RefCount = " << *m_refcount << endl;
}


//Destructor
SmartPtr::~SmartPtr()
{
    *m_refcount--;
    if(*m_refcount = 0)
    {
        delete m_ptr;
        m_ptr = NULL;

    }

    cout << "SmartPtr Destructor, RefCount = " << *m_refcount << endl;
}


//Operator=
SmartPtr& SmartPtr::operator=(const SmartPtr& other)
{
    if (this != &other)
    {

        if (--(*m_refcount) <= 0)
        {
    
            delete m_ptr;
            delete m_refcount;
        }

        if (other.m_ptr) 
        {
            m_refcount = other.m_refcount;
            (*m_refcount)++;
        } 
        else 
        {
            
            m_refcount = new size_t;
            *m_refcount = 0;
        }

        m_ptr = other.m_ptr;
    }

    cout << "SmartPtr Copy Assignment, RefCount = " << *m_refcount << endl;

    return *this;
    
}


//Operator*
DataType& SmartPtr::operator*()
{
    return (*this->m_ptr);
}


//Operator->
DataType* SmartPtr::operator->()
{
    return (this->m_ptr);
}