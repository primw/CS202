// Prim Wandeevong  // CS 202 - Library.h // 10-17-19 //
#ifndef LibraryH
#define LibraryH
using namespace std;

const int LIBRARY_BOOKS = 1000;

class Library
{
    private:
        char m_name[255];
        Book m_inventory[LIBRARY_BOOKS];

    public:
        const char* getName() const;
        void setName(const char* name);
        Book* findOpenSpot();
        Book* operator[](const char* title);
        Book& operator[](int index);
        bool rentBook(const int index, const char* name);
        bool operator+(const Book& myBook);
        friend ostream& operator<<(ostream& os, const Library& lib);
        Library(const char* name);
};

#endif