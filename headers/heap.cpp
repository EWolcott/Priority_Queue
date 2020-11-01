#include "heap.h"

//make sure that the added item is not of greater value than its parent
template <typename T>
void cs273::heap<T>::insert(T &item)
{
    data.push_back(item);         //add the item to the next available node position (furthest right)
    int child = data.size() - 1;  //assign the child position value at the end of the vector
    int parent = (child - 1) / 2; //assign the parent position value at the corresponding vector location
    while (parent >= 0 && data[parent] < data[child])
    {                                         //make sure the child is not larger than the parent
        std::swap(data[parent], data[child]); //swap the two until it's true
        child = parent;
        parent = (child - 1) / 2;
    }
}

//removes the first element in the heap and discards it.
//all subsequent data shuffles.
template <typename T>
void cs273::heap<T>::remove()
{
    data[0] = data[data.size() - 1];
    int parent = 0;
    while (true)
    {
        int child1 = 2 * parent + 1;
        int child2 = 2 * parent + 2;
        if (child1 > data.size())
            break;
        int maxchild = child1;
        if (child2 < data.size() && data[child1] < data[child2])
            maxchild = child2;
        if (data[parent] < data[maxchild])
        {
            std::swap(data[parent], data[maxchild]);
            parent = maxchild;
        }
        else
            break;
    }
    data.pop_back();
}

//return the element at that top of the heap
template <typename T>
const T &cs273::heap<T>::top()
{
    return data[0];
}

//calls the vector empty method and returns a bool
template <typename T>
bool cs273::heap<T>::empty()
{
    return data.empty();
}

//called the vector size method and returns the size of vector
template <typename T>
int cs273::heap<T>::size()
{
    return data.size();
}
