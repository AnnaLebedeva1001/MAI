#include <iostream>
#include <deque>
#include "List.h"

template <template <typename T, typename _allocator = std::allocator<T>> typename Container, typename T>
class Decorator
{
public:
    virtual void push_back(T val) = 0;
    typename virtual Container<T>::iterator begin() = 0;
    typename virtual Container<T>::iterator end() = 0;
};

template <template<typename T, typename _allocator = allocator<T>> typename Container, typename T>
class Decorator_for_List : public Decorator<Container, T>
{
private:
    Container<T> list;
public:
    void push_back(T val)
    {
        list.Push_back(val);
    }

    typename Container<T>::iterator begin() { return list.Begin(); }

	typename Container<T>::iterator end() { return list.End(); }
};

template <template<typename T, typename _allocator = allocator<T>> typename Container, typename T>
class Decorator_for_deque : public Decorator<Container, T>
{
private:
	Container<T> deque;
public:
    void push_back(T val)
    {
        deque.push_back(val);
    }

    typename Container<T>::iterator begin() { return deque.begin(); }
	typename Container<T>::iterator end() { return deque.end(); }
};