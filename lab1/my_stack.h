template <typename T>
class my_stack
{
public:
	my_stack();
	~my_stack();
	void Push(T news);
	T Pop();
	bool isEmpty();
	void Print();
	T * operator[](int index);
	int stack_size();
	my_stack * short_name()
	{
		my_stack* newSt = new my_stack(*this);
		Node* tmp = newSt->top;
		while (tmp)
		{
			tmp->news->change_string();
			tmp = tmp->p;
		}
		return  newSt;
	}
	my_stack(my_stack const & obj);

private:
	struct Node
	{
		T news;
		Node *p;
	};
	int size = 0;
	Node *top;
};


template <typename T>
class my_stack
{
public:
	my_stack() :top(NULL)
	{

	}
	~my_stack()
	{
		while (top)
		{
			Node *pv = top;
			top = top->p;
			delete pv;
		}

	}
	my_stack operator = (const my_stack &st)
	{
		Node* tmp = st.top;
		if (tmp)
		{
			Node* newNode = new Node();
			newNode->news_st = T(tmp->news_st);
			this->top = newNode;
			while (tmp->p)
			{
				tmp = tmp->p;
				newNode->p = new Node();
				newNode = newNode->p;
				newNode->news_st = T(tmp->news_st);
			}
		}
		size = st.size;
		return *this;
	}
	void Push(T newss)
	{
		Node *pv = new Node;
		pv->news_st = newss;
		pv->p = top;
		top = pv;
		size++;
	}
	T Pop()
	{
		if (isEmpty())
		{
			return NULL;
		}
		T temp = top->news_st;
		Node *pv = top;
		top = top->p;
		delete pv;
		size--;
		return temp;
	}
	bool isEmpty()
	{
		return top ? false : true;
	}
	void Print()
	{
		while (top)
		{
			std::cout << Pop() << ' ' << endl;
		}

		std::cout << std::endl;
	}
	T  operator[](int index)
	{
		int i = 0;
		my_stack *tmp = new my_stack(*this);
		while (!tmp->isEmpty())
		{
			if (i == index)
				return tmp->Pop();
			tmp->Pop();
			i++;
		}
		delete tmp;
		return NULL;
	}

	int stack_size()
	{
		return size;
	}
	my_stack * short_name()
	{
		my_stack* newSt = new my_stack(*this);
		Node* tmp = newSt->top;
		while (tmp)
		{
			tmp->news_st->change_string();
			tmp = tmp->p;
		}
		return  newSt;
	}
};