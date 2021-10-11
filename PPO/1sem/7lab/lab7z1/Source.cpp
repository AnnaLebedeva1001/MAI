#include <iostream>
#include <string>

using namespace std;

template <typename T>
class LList
{
    struct node
    {
        T value;
        node* prev;
        node* next;
        node(T value, node* prev = nullptr, node* next = nullptr)
            : value{ move(value) }, prev{ prev }, next{ next }
        {}
        node(const node&) = delete;
    };

public:
    LList() = default;
    LList(const LList<T>&);
    ~LList();
    T& get(size_t pos) const;
    void insert(T value, size_t pos);
    T remove(size_t pos);
    double arithmetic_mean_elements(LList <T> arr, size_t n);

private:
    size_t n_elements = 0;
    node head = { T{}, nullptr, &tail };
    node tail = { T{}, &head, nullptr };
};

template<typename T>
LList<T>::LList(const LList<T>& other)
{
    for (auto i = other.n_elements; i > 0; --i)
    {
        insert(other.get(i - 1), 0);
    }
}

template <typename T>
LList<T>::~LList()
{
    for (auto p = head.next; p != &tail; )
    {
        auto next = p->next;
        delete p;
        p = next;
    }
}

template<typename T>
T& LList<T>::get(size_t pos) const
{
    auto p = head.next;
    while (pos--)
        p = p->next;
    return p->value;
}

template<typename T>
void LList<T>::insert(T value, size_t pos)
{
    auto p = &head;
    while (pos--)
        p = p->next;
    auto next = p->next;
    next->prev = p->next = new node(move(value), p, next);
    ++n_elements;
}

template<typename T>
T LList<T>::remove(size_t pos)
{
    auto p = head.next;
    while (pos--)
        p = p->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    auto value = move(p->value);
    delete p;
    --n_elements;
    return value;
}

template <typename T>
double LList<T>::arithmetic_mean_elements(LList <T> arr, size_t n)
{
    size_t i;
    double avg_r = 0;
    for (i = 0; i < n; i++)
    {
        avg_r += arr.get(i) / n;
    }
    return avg_r;
}

int main()
{
    LList <double> mylist, list;
    string v;
    int count = 0, i;
    size_t p;
    cout << "Enter the values and position of the item in a lws linked list (enter 'stop' instead of value to finish)" << endl;
    for (;;)
    {
        cout << "enter value" << endl;
        cin >> v;
        if (v == "stop")
            break;
        cout << "enter position" << endl;
        cin >> p;
        mylist.insert(stoi(v), p);
    }
    cout << "Mylist: ";
    for (i = 0; i <= p; i++)
    {
        cout << mylist.get(i) << ' ';
        if (mylist.get(i) == 1)
            count++;
    }
    cout << endl << "Number of 1-s in the list: " << count << endl;

    cout << list.arithmetic_mean_elements(mylist, p) << endl;

    return 0;
}