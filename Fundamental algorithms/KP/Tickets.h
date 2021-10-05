#include <vector>
#include <iostream>

using namespace std;

vector<int> get_numbers_(vector<int> numbers, int n_)
{
	vector<int> n;
	for (int i = 0; i < n_; i++)
	{
		n.push_back(numbers[i]);
	}
	return n;
}

class Ticket
{
public:
	virtual ~Ticket() {};
	virtual vector<int> get_numbers() = 0;
	virtual int get_id() const = 0;
};

class Ticket_5_36: public Ticket
{
private:
	vector<int> numbers;
    int id;
public:

	Ticket_5_36(vector<int> numbers_, int series) :id(series)
	{
		numbers = { 0, 0, 0, 0, 0 };
		for (int i = 0; i < 5; i++)
		{
			numbers[i] = numbers_[i];
		}
	}

	vector<int> get_numbers()
    {
		return get_numbers_(numbers, 5);
	}

	int get_id() const
    {
		return id;
	}
};


class Ticket_6_49 :public Ticket
{
private:
	vector<int> numbers;
    int id;
public:
	Ticket_6_49(vector<int> numbers_, int series) :id(series)
	{
		numbers = { 0, 0, 0, 0, 0, 0 };
		for (int i = 0; i < 6; i++)
		{
			numbers[i] = numbers_[i];
		}
	}

	vector<int> get_numbers()
	{
		return get_numbers_(numbers, 6);
	}

	int get_id() const
    {
		return id;
	}
};