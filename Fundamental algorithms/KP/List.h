#include <iostream>

using namespace std;


template <typename T, typename _allocator = allocator<T>>
class List
{
public:
    struct node
    {
        node* prev;
        node* next;
        T value;
        node(T t, node* p, node* n) : value(t), prev(p), next(n) {}
        node(const node&) = delete;
        void operator=(const node&) = delete;
    };

    class iterator
    {
    private:
        node *Node;

    public:
        iterator() {}
        iterator(node *node) : Node(node) {}
        ~iterator() {}

        T &operator*() { return Node->value; }

        T *operator->() { return &(Node->value); }

        bool operator==(iterator iter) { return (Node == iter.Node); }
        bool operator!=(iterator iter) { return (Node != iter.Node); }

        iterator &operator=(iterator &other)
        {
            Node = other.Node;
            return (*this);
        }

        iterator& operator++(int)
        {
            Node = Node->next;
            return (*this);
        }

		iterator &operator++()
        {
            Node = Node->next;
            return (*this);
        }

        iterator &operator--()
        {
            Node = Node->prev;
            return (*this);
        }
    };

    typedef iterator MyListIterator;

private:
    node* head;
    node* tail;

public:

    List() : head(NULL), tail(NULL) {}

    bool Empty() const { return (!head || !tail); }

    ~List()
    {
        Clear();
    }

    void Push_back(T data)
    {
        tail = new node(data, tail, NULL);
        if (tail->prev)
            tail->prev->next = tail;

        if (Empty())
            head = tail;
    }


    void Clear()
    {
        while (head)
        {
            node* temp(head);
            head = head->next;
            delete temp;
        }
    }

    MyListIterator Begin() const { return MyListIterator(head); }

    MyListIterator End() const { return MyListIterator(nullptr); }

    MyListIterator Find(MyListIterator first, MyListIterator last, const T &val)
    {
        while (first != last)
        {
            if (*first == val)
                return first;
            ++first;
        }
        return last;
    }
};
