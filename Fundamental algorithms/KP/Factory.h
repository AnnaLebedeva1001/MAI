#include <ctime>
#include <memory>
#include "Tickets.h"

using namespace std;


class Abstract_factory
{
public:
	virtual ~Abstract_factory() {};
	virtual shared_ptr<Ticket> make_ticket() const = 0;
};

class Factory_5_36 : public Abstract_factory
{
private:
	mutable int series;
public:
	Factory_5_36()
	{
		series = 0;
		srand(time(0));
	}

	shared_ptr<Ticket> make_ticket() const
	{
		vector<int> numbers(5);
		for (int i = 0; i < 5;)
		{
			int a = 1 + rand() % 36;
			bool flag = true;
			for (int k = 0; k < i; k++)
			{
				if (numbers[k] == a)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				numbers[i] = a;
				i++;
			}
		}
		series += 1;
		return  shared_ptr<Ticket>{(Ticket*)(new Ticket_5_36(numbers, series))};
	}
};

class Factory_6_49 : public Abstract_factory
{
private:
	mutable int series;
public:
	Factory_6_49()
	{
		series = 0;
		srand(time(0));
	}

	shared_ptr<Ticket> make_ticket() const
	{

		vector<int> numbers(6);
		for (int i = 0; i < 6;)
		{
			int a = 1 + rand() % 49;
			bool flag = true;
			for (int k = 0; k < i; k++)
			{
				if (numbers[k] == a)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				numbers[i] = a;
				i++;
			}
		}
		series += 1;
		return  shared_ptr<Ticket>{(Ticket*)(new Ticket_6_49(numbers, series))};
	}
};