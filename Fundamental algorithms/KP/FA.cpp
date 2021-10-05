#include <iostream>
#include "Lottery.h"

using namespace std;

int main()
{
    Lottery new_lottery;
    new_lottery.start_5_36();
    //new_lottery.start_6_49();
    cout << endl;
    new_lottery.print_results();
    new_lottery.print_print_of_the_winners_base();
    cout << endl;
    int id;
    Win_ticket tic;
    Decorator<deque, Win_ticket>* win_result = new Decorator_for_deque<deque, Win_ticket>;
    //Decorator<List, Win_ticket>* win_result = new Decorator_for_List<List, Win_ticket>;
    int win;
    History history;

    while (true)
    {
        int flag;
        cout << "If you want to know the ticket number of the last lottery, press 1;" << endl
            << "If you want to find all tickets by the winning amount of the last lottery, press 2;" << endl
            << "If you want to start a new lottery 5 of 36, press 3;" << endl
            << "If you want to start a new lottery 6 of 49, press 4;" << endl
            << "If you want to end the lottery press 0;" << endl;
        cin >> flag;
        switch (flag)
        {
        case 0:
            delete win_result;
            history.delete_history();
            return 0;
            break;
        case 1:
            cout << "Enter ticket number:" << endl;
            cin >> id;
            tic = new_lottery.search_by_ticket_number(id);
            if (tic.ticket)
            {
                cout << "id: " << tic.ticket->get_id() << " win: " << tic.win << endl;
            }
            else
            {
                cout << "No ticket with this ID found!!!" << endl;
            }
            break;
        case 2:
            cout << "Enter the amount of winnings:" << endl;
            cin >> win;
            win_result = new_lottery.search_by_winnings(win);
            for (auto i = win_result->begin(); i != win_result->end(); i++)
            {
                cout << "Number: " << i->ticket->get_id() << " win: " << i->win << endl;
            }
            break;
        case 3:
            delete win_result;
            win_result = new Decorator_for_deque<deque, Win_ticket>;
            //win_result = new Decorator_for_List<List, Win_ticket>;
            history.add(new_lottery);
            new_lottery.delete_results();
            new_lottery.start_5_36();
            cout << endl;
            new_lottery.print_results();
            cout << endl;
            break;
        case 4:
            delete win_result;
            win_result = new Decorator_for_deque<deque, Win_ticket>;
            //win_result = new Decorator_for_List<List, Win_ticket>;
            history.add(new_lottery);
            new_lottery.delete_results();
            new_lottery.start_6_49();
            cout << endl;
            new_lottery.print_results();
            cout << endl;
            break;
        default:
            break;
        }
    }
}