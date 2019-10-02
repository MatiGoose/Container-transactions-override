#include <iostream>
using namespace std;
class news
{
protected:
	char * date;
	char * name;
	int views;
	friend bool operator == (const news& left, const news& right);
public:
	friend ostream& operator<<(ostream& out, const news & news);
	friend istream& operator>>(istream& in, news & news);
	news();
	~news();
	news(news const& copy);
	news(char const * Date, char const * Name, int Views);
	void set_date(char const * Date);
	void set_name(char const * Name);
	void set_views(int Views);


	char const *get_date();
	char const *get_name();
	int	get_views();
	void change_string();
	//void print(ostream &s);
};