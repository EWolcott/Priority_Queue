#ifndef HEAP_H
#define HEAP_H

namespace cs273
{
    template <typename T>
    class heap
    {
    private:
        std::vector<T> data;

    public:
        void insert(T &item); //adds an item to the heap
        void remove();        //removes the top item from the heap
        const T &top();       //returns the value of top item in heap
        bool empty();         //checks if vector is empty
        int size();           //returns vector size
    };
} // namespace cs273

#include "heap.cpp"

#endif