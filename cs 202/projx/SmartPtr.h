// Prim Wandeevong // CS 202 - ProjectX // 11-1-19 //
#ifndef yah
#define yah
#include "DataType.h"

class SmartPtr
{
    private:
        DataType* m_ptr;
        size_t* m_refcount;

    public:
        SmartPtr();
        SmartPtr(DataType* dtPtr);
        SmartPtr(const SmartPtr& other);
        ~SmartPtr();
        SmartPtr& operator=(const SmartPtr& other);
        DataType& operator*();
        DataType* operator->();
};

#endif