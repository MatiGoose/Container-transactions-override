#include "transactions.cpp"
#include <iostream>
#include "news.h"
using namespace std;


//template <typename T>
void fun_transact(transactions<news> &t)
{
	t.BeginTrans();
	while (true)
	{
		try
		{
			t.input();
			t.Commit();
			return;
		}
		catch (...)
		{
			t.RollBack();
		}
	}
}

int main()
{
	transactions<news> trans;
	fun_transact(trans);
	cout << trans.that_trans;

	system("pause");
	return 0;
}

