#ifndef PQUEUE_H
#define PQUEUE_H
#include "heap.h"

//The priority queue is an adapter for a heap that removes the elements of greatest value first.
namespace cs273
{
    template <typename T>
    class priority_queue
    {
    private:
        heap<T> _heap;

    public:
        void push(T &item) { _heap.insert(item); } //add an item to the heap
        void pop() { _heap.remove(); }             //remove the first item (greatest value) from heap
        const T &top() { return _heap.top(); }     //peek at value of top item
        int size() { return _heap.size(); }        //return size of heap
        bool empty() { return _heap.empty(); }     //check if heap is empty
    };
} // namespace cs273

#endif