#include <iostream>
using namespace std;

template <typename T>
class transactions
{
public:
	T * that_trans;
	T * previous_trans;
	transactions() : previous_trans(NULL), that_trans(new T)
	{

	}
	void input()
	{
		cin >> *that_trans;
	}
	/*friend istream& operator >> (istream& in,transactions<T> &obj)
	{
		cin >> *that_trans;
		return in;
	}
	friend ostream& operator << (ostream& out, transactions<T> const &obj)
	{
		return *that_trans;
	}*/
	~transactions()
	{
		delete that_trans;
		delete previous_trans;
	}
	void BeginTrans()
	{
		delete previous_trans;
		previous_trans = that_trans;
		that_trans = new T(*previous_trans);
	}
	void Commit()
	{
		delete previous_trans;
		previous_trans = nullptr;
	}
	void RollBack()
	{
		if (previous_trans != nullptr)
		{
			delete that_trans;
			that_trans = previous_trans;
			previous_trans = nullptr;
		}
	}
};
