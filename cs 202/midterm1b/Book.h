// Prim Wandeevong // CS 202 - Book.h // 10-16-19 //

#ifndef BookH
#define BookH
using namespace std;

const int DEFAULT_ISBN[13] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

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
        Book(const char* title = "norenter", const int* isbn = DEFAULT_ISBN, const char* renter = "norenter");
        Book(const Book & other);
        ~Book();
        Book& operator= (const Book& other);

        void setTitle(const char* title);
        void setIsbn(const int* isbn);
        void setAvailable(const bool available);
        void setRenter(const char* renter);

        const int getId() const;
        const char* getTitle() const;
        const int* getIsbn() const;
        const bool getAvailable() const;
        const char* getRenter() const;
        const int getIdgen() const;

        bool valid();
        bool operator+(const char* renter);
        void free();
        friend ostream& operator<<(ostream& os, const Book& myBook);

};

#endif