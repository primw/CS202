// Prim Wandeevong // CS 202 - Book.h // 10-16-19 //

#ifndef BookH
#define BookH
using namespace std;

class Book
{
    private:
        const int m_id;
        char m_title[255];
        int m_isbn[13];
        bool m_available;
        char m_renter[255];
        static int s_idgen;

    public:
        Book();
        Book(char* title, int* isbn = DEFAULT_ISBN, char* renter = DEFAULT_STR);
        Book(const Book & other);
        ~Book();
        Book& operator= (const Book& other);

        void setTitle(char* title);
        void setIsbn(int* isbn);
        void setAvailable(bool available);
        void setRenter(char* renter);

        const int getId() const;
        const char* getTitle() const;
        const int* getIsbn() const;
        const bool getAvailable() const;
        const char* getRenter() const;
        const int getIdgen() const;

        bool valid();
        bool operator+(char* renter);
        void free();
        friend ostream& operator<<(ostream& os, const Book& myBook);

};

#endif