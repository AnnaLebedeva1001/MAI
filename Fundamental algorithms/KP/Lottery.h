#include <vector>
#include "Decorator.h"
#include "Factory.h"

const int size_of_circulation = 8000;

struct Win_ticket
{
    int win; //1-1 2-10 3-100 4-1000 5-10000
    shared_ptr<Ticket> ticket;
};

class Lottery
{
private:
    Decorator<deque, Win_ticket> *result;
    //Decorator<List, Win_ticket>* result;

    void start(const Abstract_factory &factory)
    {
        result = new Decorator_for_deque<deque, Win_ticket>;
        //result = new Decorator_for_List<List, Win_ticket>;
        Decorator<deque, shared_ptr<Ticket>> *tickets__ = new Decorator_for_deque<deque, shared_ptr<Ticket>>;
        //Decorator<List, shared_ptr<Ticket>>* tickets__ = new Decorator_for_List<List, shared_ptr<Ticket>>;
        for (size_t i = 0; i < size_of_circulation; i++)
        {
            tickets__->push_back(factory.make_ticket());
        }
        Decorator<deque, shared_ptr<Ticket>> *tirag = new Decorator_for_deque<deque, shared_ptr<Ticket>>;
        //Decorator<List, shared_ptr<Ticket>>* tirag = new Decorator_for_List<List, shared_ptr<Ticket>>;
        for (auto ticket = tickets__->begin(); ticket != tickets__->end(); ticket++)
        {
            int r = 1 + rand() % 100;
            if (r < 50)
                tirag->push_back(*ticket);
        }
        shared_ptr<Ticket> win_ticket = factory.make_ticket();
        vector<int> win_numbers = win_ticket->get_numbers();
        cout << "Winning ticket : ";
        for (auto &i : win_numbers)
        {
            cout << i << "  ";
        }
        cout << endl;

        for (auto &n : win_numbers)
        {
            for (auto ticket = tirag->begin(); ticket != tirag->end(); ticket++)
            {
                vector<int> ticket_numbers = (*ticket)->get_numbers();
                bool flag = false;
                for (auto &number : ticket_numbers)
                {
                    if (number == n)
                    {
                        flag = true;
                    }
                }
                if (flag)
                {
                    bool find = false;
                    for (auto prize_ticket = result->begin(); prize_ticket != result->end(); prize_ticket++)
                    {
                        if ((*ticket)->get_id() == prize_ticket->ticket->get_id())
                        {
                            find = true;
                            (*prize_ticket).win = (*prize_ticket).win * 10;
                            break;
                        }
                    }
                    if (find == false)
                        result->push_back(Win_ticket{1, (*ticket)});
                }
            }
        }
        delete tickets__;
        delete tirag;
    }

public:
    void start_5_36()
    {
        return start(Factory_5_36());
    }

    void start_6_49()
    {
        return start(Factory_6_49());
    }

    void print_print_of_the_winners_base()
    {

        for (auto i = result->begin(); i != result->end(); i++)
        {
            vector<int> ticket_numbers = i->ticket->get_numbers();

            cout << "ticket number: " << i->ticket->get_id() << " numbers: ";
            for (auto &i : ticket_numbers)
            {
                cout << i << "  ";
            }
            cout << "won: " << i->win << endl;
        }
    }

    void print_results()
    {
        int count_1 = 0, count_10 = 0, count_100 = 0, count_1000 = 0;

        for (auto i = result->begin(); i != result->end(); i++)
        {
            switch (i->win)
            {
            case 1:
                count_1++;
                break;
            case 10:
                count_10++;
                break;
            case 100:
                count_100++;
                break;
            case 1000:
                count_1000++;
                break;
            case 10000:
                cout << "Winner id: " << i->ticket->get_id() << " the winning amount is 10,000!!!" << endl;
                break;
            case 100000:
                cout << "Super winner id: " << i->ticket->get_id() << " the winning amount is 100,000!!!" << endl;
                break;
            default:
                break;
            }
        }
        cout << "Number of players who guessed 1 number: " << count_1 << endl 
        << "Number of players who guessed 2 number: " << count_10 << endl 
        << "Number of players who guessed 3 number: " << count_100 << endl
        << "Number of players who guessed 4 number: " << count_1000 << endl;
    }

    Win_ticket search_by_ticket_number(int id)
    {
        bool flag = false;
        Win_ticket res;
        for (auto i = result->begin(); i != result->end(); i++)
        {
            if (i->ticket->get_id() == id)
                res = *i;
        }
        return res;
    }

    Decorator<deque, Win_ticket> *search_by_winnings(int win)
    //Decorator<List, Win_ticket>* search_by_winnings(int win)
    {
        Decorator<deque, Win_ticket> *res = new Decorator_for_deque<deque, Win_ticket>; 
        //Decorator<List, Win_ticket>* res = new Decorator_for_List<List, Win_ticket>;
        for (auto i = result->begin(); i != result->end(); i++)
        {
            if (i->win == win)
            {
                res->push_back(*i);
            }
        }
        return res;
    }

    void delete_results()
    {
        delete result;
    }
};

class History
{
private:
    Decorator<deque, Lottery> *lotteries = new Decorator_for_deque<deque, Lottery>;
    //Decorator<List, Lottery>* lotteries = new Decorator_for_List<List, Lottery>;
public:
    void add(Lottery lottery)
    {
        lotteries->push_back(lottery);
    }

    void delete_history()
    {
        delete lotteries;
    }
};