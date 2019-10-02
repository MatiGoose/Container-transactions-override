#include <iostream>
#include "news.h"
using namespace std;
//сокращение названия новости
void news::change_string()
{
	char * tmp = name;
	int index1, index2;
	index1 = 0;

	// ищем первый пробел
	while (tmp[index1] != '\0')
	{
		if (tmp[index1] == ' ')
			break;
		index1++;
	}
	index2 = strlen(tmp);
	if (index1 == index2)
		return;
	while (tmp[index2] != ' ')
	{
		index2--;
	}
	int size;
	size = index1 + strlen(tmp) - index2 + 5;
	name = new char[size + 1];
	index1 = 0;
	while (tmp[index1] != ' ')
	{
		name[index1] = tmp[index1];
		index1++;
	}
	name[index1] = ' ';
	name[index1 + 1] = '.';
	name[index1 + 2] = '.';
	name[index1 + 3] = '.';
	name[index1 + 4] = ' ';
	index2 = strlen(tmp);
	name[size] = '\0';
	size--;
	while (tmp[index2] != ' ')
	{
		name[size--] = tmp[index2];
		index2--;
	}
	delete[] tmp;

}
//
bool operator == (const news& left, const news& right)
{
	return true;
}
//конструктор без параметров
news::news()
{
	date = NULL;
	name = NULL;
	views = 0;
}
//конструктор с параметрами
news::news(char const * Date, char const * Name, int Views) : views(Views)
{
	if (Date)
	{
		int lenBuf = strlen(Date);
		if (lenBuf < 200)
			name = new char[lenBuf + 1];
		else
		{
			date = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(date, lenBuf + 1, Name);
	}
	else
		date = nullptr;
	if (Name)
	{
		int lenBuf = strlen(Name);
		if (lenBuf < 200)
			name = new char[lenBuf + 1];
		else
		{
			name = new char[200] + 1;
			lenBuf = 200;
		}
		strcpy_s(name, lenBuf + 1, Name);
	}
	else
		name = nullptr;

}
//конструктор копирования
news::news(news const & n) : news(n.date, n.name, n.views)
{

}
//деструктор
news::~news()
{
	delete[] date;
	delete[] name;
}
//установить название
void news::set_name(char const * Name)
{
	if (name)
		delete[]name;
	if (Name)
	{
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);
	}
	else name = NULL;
}
//установить дату
void news::set_date(char const * Date)
{
	if (date)
		delete[]date;
	if (Date)
	{
		date = new char[strlen(Date) + 1];
		strcpy_s(date, strlen(Date) + 1, Date);
	}
	else date = NULL;
}
//установить просмотры
void news::set_views(int Views)
{
	views = Views;
}
//получить просмотры
int news::get_views()
{
	return views;
}
//получить дату
char const *news::get_date()
{
	return date;
}
//получить название
char const *news::get_name()
{
	return name;
}
//перегрузка COUT
ostream& operator<<(ostream& out, const news& news)
{
	return 	out << "Date: " << news.date << "; "
		<< "Name: " << news.name << "; "
		<< "Views: " << news.views;
}
//перегрузка CIN
istream& operator>>(istream& in, news & news)
{
	char date[255];
	char name[255];
	int views;

	cout << "Date: ";
	cin.ignore();
	cin.getline(date, 255, '\n');
	news.set_date(date);
	cout << "Name: ";
	cin.getline(name, 255, '\n');
	news.set_name(name);
	cout << "Views: ";
	cin >> views;
	while (!cin.good() || views <= 0)
	{
		cout << "Input data again" << endl;
		cin.clear();
		cin.ignore();
		throw "error";
	}
	news.set_views(views);
	return in;
}