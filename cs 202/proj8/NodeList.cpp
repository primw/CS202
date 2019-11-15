// Prim Wandeevong // CS 202 - Project 8 // 11-13-19 //
#include <iostream>
#include "NodeList.h"
using namespace std;


//Default Constructor
NodeList::NodeList()
{  
    m_head = NULL;
    cout << "NodeList Default Constructor Test" << endl;
}


//Parameterized Constructor
NodeList::NodeList(size_t count, const DataType & value) 
{
    
	   Node *next = NULL;
    Node *curr = NULL;

    while (count--) {
        if (!next) {
            next = new Node(value);
        } else {
            curr = new Node(value, next);
            next = curr;
        }
    }

    m_head = curr;
    
	cout << "NodeList Parameterized Constructor Test" << endl;
}													  


//Copy Constructor
NodeList::NodeList(const NodeList& other)
{
    if (other.m_head != NULL)
    {
		m_head = new Node (other.m_head->data());
		
		Node *headCopy = m_head;
		Node *otherCopy = other.m_head;

		while (otherCopy->m_next != NULL)
        {
			otherCopy = otherCopy->m_next;
			headCopy->m_next = new Node (otherCopy->data());
			headCopy = headCopy->m_next;
        }
		headCopy->m_next = NULL;
	
	cout << "NodeList Copy Constructor Test" << endl;

    }
}


//Destructor
NodeList::~NodeList()
{
    clear();
    cout << "NodeList Destructor Test" << endl;
}


//Operator= Overload
NodeList& NodeList::operator= (const NodeList& rhs)
{
    cout << "NodeList Operator= Overload Test" << endl;
    if (this != &rhs)
    {
        Node* headCopy = m_head;
        Node* rhsCopy = rhs.m_head;

        if (this->size() < rhs.size())
        {
            clear();
            DataType newData(0,0.0);
			NodeList newList(rhs.size(), newData);
			headCopy = newList.m_head;
		}
		while (rhsCopy->m_next != NULL)
        {
			headCopy->m_data = rhsCopy->data();
			headCopy = headCopy->m_next;
			rhsCopy = rhsCopy->m_next;
		}
	}
    else
    {
		return *this;
	}
    
    return *this;
}


//Front Method
Node* NodeList::front()
{
    cout << "NodeList Front Method Test" << endl;

    if (empty())
    {
        return NULL;
    }
    else
    {
        return m_head;
    }
    
}


//Back Method
Node* NodeList::back()
{
    cout << "NodeList Back Method Test" << endl;

    Node *headTemp = m_head;
    if (empty())
    {
        return NULL;
    }
	
    else
    {
        while (headTemp->m_next != NULL)
        {
		    headTemp = headTemp->m_next;
	    }

	    return headTemp;
    }
}


//Find Method
Node* NodeList::find(const DataType & target, Node * & previous, const Node* start)
{
    cout << "NodeList Find Method Test" << endl;
	Node* nodePtr = m_head;

    while (nodePtr->m_next != NULL && nodePtr != NULL)
    {
        if (nodePtr->m_next->data() == target)
        {
            if (nodePtr != NULL)
            {
                previous = nodePtr;
            }
            else
            {
                previous = NULL;
            }
            return nodePtr->m_next;
        }
        nodePtr = nodePtr->m_next;
    }

    previous = NULL;
    return NULL;
}	


//Insert After Method
Node* NodeList::insertAfter(const DataType & target, const DataType & value)
{
    cout << "NodeList Insert After Method Test" << endl;

	Node* headTemp = m_head;
    while (headTemp != NULL)
    {
        if (headTemp->data() == target && headTemp != NULL)
        {
            headTemp->m_next = new Node (value,headTemp->m_next);
            return headTemp->m_next;
        }

        headTemp = headTemp->m_next;
    }
    if (empty())
    {
        m_head = new Node (value, NULL);
        return m_head;
    }

    return NULL;
}


//Insert Before Method
Node* NodeList::insertBefore(const DataType & target, const DataType & value)
{
    cout << "NodeList Insert Before Method Test" << endl;

    if (empty())
    {
        m_head = new Node (value, NULL);
        return m_head;
    }
    else if (m_head->data() == target)
    {
        Node* m_newHead = new Node (value, NULL);
        m_newHead->m_next = m_head;
        return m_newHead;
    }

    //I don't think this is right
    Node* h1 = NULL;
    Node* h2 = m_head;

    while (h2 != NULL)
    {
        if (h2->data() == target && h2 != NULL)
        {
            h1->m_next = new Node (value,h2);
            return h1->m_next;
        }

        h1 = h2;
        h2 = h2->m_next;
    }
    return NULL;
}



//Erase Method
Node* NodeList::erase(const DataType& target)
{
    cout << "NodeList Erase Method Test" << endl;

    if(m_head->data() == target)
    {
		m_head = m_head->m_next;
		return m_head;
	}

	if(empty())
    {
		return NULL;
	}
	else
    {
		Node *h1;
		Node *h2;
		h2 = find(target, h1);

		if(h2 != NULL)
        {
			h1->m_next = h2->m_next;
			delete h2;
			return h1;
		}
	}

	return NULL;
}


//Operator[] Overload
DataType& NodeList::operator[] (size_t position)
{
    int i = 0;
	Node *curr = m_head;

	while (i < position)
    {
		curr++;
	}

	return curr->data();
}


//Const Operator[] Overload
const DataType& NodeList::operator[] (size_t position) const
{
    int i = 0;
	Node *curr = m_head;

	while (i < position)
    {
		curr++;
	}
	return curr->data();
}


//Size Method
size_t NodeList::size() const
{
    cout << "NodeList Size Method Test" << endl;
	Node *curr = m_head;
    size_t size = 0;

    while (curr) {
        size++;
        curr = curr->m_next;
    }

    return size;
}												


//Empty Method
bool NodeList::empty() const
{
    cout << "NodeList Empty Method Test" << endl;

	if(m_head == NULL)
    {
		return 1;
	}
	else
    {
        return 0;
    }
    
	
}		


//Clear Method
void NodeList::clear()
{
    cout << "NodeList Clear Method Test" << endl;

	Node* curr = m_head;
	Node* pre = m_head;

	while (curr != NULL)
    {
		curr = curr->m_next;
		delete pre;
		pre = curr;
	}

	m_head = NULL;	
}	


//Friend Operator<< Overload
ostream & operator<<(ostream & os, const NodeList& nodeList)
{
    cout << "Friend Operator<< Overload Test" << endl;
	size_t i = 0;
	while (i < nodeList.size()){
		os << '{' << i << ',' << nodeList[i] << "} " << std::endl;
        i++;
	}
	return os;
}