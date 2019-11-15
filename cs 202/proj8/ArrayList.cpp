// Prim Wandeevong // CS 202 - Project 8 // 11-12-19 // I don't know what I'm doing //
#include <iostream>
#include "ArrayList.h"
using namespace std;


//Default Constructor
ArrayList::ArrayList()
{
    m_array = NULL;
    m_size = 0;
    m_maxsize = 0;

    cout << "Array List Default Constructor Test" << endl;

}


//Parameterized Constructor
ArrayList::ArrayList(size_t count, const DataType& value) : m_size(count), m_maxsize(count)
{
    int i = 0;
    m_array = NULL;
    m_array = new DataType [m_maxsize];

    while (i != m_maxsize)
    {
        m_array[i] = value;
        i++;
    }

    cout << "Array List Parameterized Constructor Test" << endl;
}


//Copy Constructor
ArrayList::ArrayList(const ArrayList& other) : m_size(other.m_size), m_maxsize(other.m_maxsize)
{
    int i = 0;
    m_array = NULL;
    m_array = new DataType[m_size];

    while (i != m_maxsize)
    {
        m_array[i] = other.m_array[i];
    }

    cout << "Array List Copy Constructor Test" << endl;
}


//Destructor
ArrayList::~ArrayList()
{
    clear();
    cout << "Array List Destructor Test" << endl;
}


//Operator= Overload
ArrayList& ArrayList::operator= (const ArrayList& rhs)
{
    if (this != &rhs)
    {
        int i = 0;
        m_maxsize = rhs.m_maxsize;
        m_size = rhs.m_size;

        while (i != m_maxsize)
        {
            m_array[i] = rhs.m_array[i];
        }
    }

    else
    {
        return *this;
    }

    cout << "Array List Operator= Test" << endl;

    return *this;

}


//Front Method
DataType* ArrayList::front()
{
    cout << "Array List Front Method Test" << endl;

    if (m_array != NULL)
    {
        return &m_array[0];
    }
    else
    {   
        cout << "The list is empty :(" << endl;
        return NULL;
    }
    
}


//Back Method
DataType* ArrayList::back()
{
    cout << "Array List Back Method Test" << endl;

    if (m_array != NULL)
    {
        return &m_array[m_size]; 
    }
    else
    {
        cout << "The list is empty :(" << endl;
        return NULL;
    }
    
}


//Find Method
DataType* ArrayList::find(const DataType & target, DataType * & previous, const DataType * start)
{
    cout << "Find Method Test" << endl;

    DataType* arrayPtr = m_array;
    int i = 0;

    if (m_array != NULL)
    {
        while (i < m_maxsize)
        {   
            if (*arrayPtr == target)
            {
                arrayPtr--;

                if (arrayPtr != NULL)
                {
                    previous = arrayPtr;
                }
                else
                {
                     previous =  NULL;
                }
                
                arrayPtr++;
                return arrayPtr;
            }   
            i++;
            arrayPtr++;
        }
    }

    else
    {
        previous = NULL;
        return NULL;
    }
    
}


//insertAfter Method
DataType* ArrayList::insertAfter(const DataType& target, const DataType& value)
{
    cout << "Insert After Method Test" << endl;       //I really don't know what I'm doing

    DataType* current = m_array;
    int i = 0;

    while (current != NULL)
    {
        if (target == *current)
        {
            for (int k = m_size - 1; k > i; k--)
            {
                m_array[k] = m_array[k-1];
            }

            m_array[i + 1] = value;
            *current = m_array[i +1];
            
            return current;
        }

        i++;
        current++;
    }

    if (empty())
    {
        m_array[0] = value;
        *current = m_array[0];
        m_size++;

        return current;
    }

    return NULL;
}

//Insert Before Method
DataType* ArrayList::insertBefore(const DataType& target, const DataType& value)
{
    cout << "Insert Before Method Test" << endl;       //I really don't know what I'm doing

    DataType* current = m_array;
    int i = 0;

    while (current != NULL)
    {
        if (target == *current)
        {
            for (int k = m_size - 1; k > i; k--)
            {
                m_array[k] = m_array[k-1];
            }

            m_array[i] = value;
            
            return current;
        }

        i++;
        current++;
    }

    if (empty())
    {
        m_array[0] = value;
        *current = m_array[0];
        m_size++;

        return current;
    }

    return NULL;
}


//Erase Method
DataType* ArrayList::erase(const DataType& target)
{
    cout << "Erase Method Test" << endl;

    DataType* current = m_array;
    int count = 0;

    while (current != NULL)
    {
        if (target == *current)
        {
            for (int i = count; i < m_size; i++)
            {
                m_array[i-1] = m_array[i];
            }

            if (count == 0)
            {
                return m_array;
            }
            else
            {
                return current--;                
            }
            
        }
        current++;
        count++;
    }

    return NULL;
}


//Operator[] Overload
DataType& ArrayList::operator[] (size_t position)
{
    return m_array[position];
}


//Size Method
size_t ArrayList::size() const
{
    return m_size;
}


//Empty Method
bool ArrayList::empty() const
{
    if (m_array == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}


//Clear Method
void ArrayList::clear()
{
    if (m_array != NULL)
    {
        delete [] m_array;
        m_array = NULL;
    }

    m_size = 0;
    m_maxsize = 0;
}


//Resize Method
void ArrayList::resize(size_t count)
{
    size_t i = 0; 
	DataType *placeHolder = new DataType[m_size];  //I'm so confused

	if (m_array != NULL)
    {
		while (i < m_size)
        {
			placeHolder[i] = m_array[i];
			i++;	
		}
	}

    else
    {
		while (i < m_size)
        {
			placeHolder = NULL;
			placeHolder++;
			i++;
		}
	}

	delete [] m_array;
	m_array = NULL;
	
	m_maxsize = m_maxsize + count;
    m_array = new DataType[m_maxsize];
    
	i = 0;
	while (i < m_maxsize)
    {
		if (m_size < m_maxsize && i > m_size)
        {
			m_array = 0;
		}
		
		m_array = placeHolder;
		placeHolder++;
		m_array++;
		i++;
	}
}


//Friend Operator<< Overload
ostream & operator<<(ostream & os, const ArrayList & arrayList)
{
    cout << "Friend Operator<< Overload Test" << endl;

	int i = 0;
	while (i < arrayList.m_size)
    {
		os << '{' << i << ',' << arrayList.m_array[i] << "} " << endl;
		i++;
	}
	return os;
}