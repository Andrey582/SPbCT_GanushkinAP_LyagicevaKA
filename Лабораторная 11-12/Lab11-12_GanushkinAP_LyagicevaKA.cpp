#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class Stack
{
private:
	T* stackPtr;
    int size;
	int top;
	int i = 0;
public:
	Stack()
	{
		size = 10;
		stackPtr = new T[size];
		top = size - 1;
		
	};

	Stack(int size) {
		if (size < 0) 
		{
			this->size = 10;
			stackPtr = new T[this->size];
			top = this->size - 1;
		}

		else
		{
			stackPtr = new T[size];
			top = size - 1;
		}
		
	}

	Stack(const Stack& other)
	{
		this->size = other.size;
		stackPtr = new T[other.size];
		this->top = other.top;
		for (int i = 0; i < size; i++)
			stackPtr[i] = other.stackPtr[i];

	}

	~Stack() {
		delete[] stackPtr;
	};

	Stack& operator +(T value)
	{
		stackPtr[top] = value;
		top--;
		return *this;
	}

	Stack& operator =(const Stack& other)
	{
		for (int i = 0; i < size; i++)
			{
				stackPtr[i] = other.stackPtr[i];
			}
		this->top = other.top;
		return *this;
	}

	T& operator --()
	{
		top++;
		T value = stackPtr[top];
		stackPtr[top] = stackPtr[top - 1];
		return value;
	}

	bool operator() ()
	{
		if (top != size - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void printStack() {
		for (int i = top + 1; i < size; i++)
			cout << stackPtr[i] << endl;

	};
	
	
};


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Проверка на int" << endl;
	Stack <int> a;
	a + 3 + 5 + 10 + 13 + 2;
	--a;
	if (a())
		a.printStack();
	else
		cout << "Стек пустой";

	cout << "\n\nПроверка операции присваивания для int" << endl;
	Stack <int> a2;
	a2 = a;
	a2.printStack();


	cout << "\n\n\nПроверка на string" << endl;
	Stack <string> b;
	b + "hello" + "how are you" + "great" + "aloha";
	--b;
	if (b())
		b.printStack();
	else
		cout << "Стек пустой";

	cout << "\n\nПроверка операции присваивания для string" << endl;
	Stack <string> b2;
	b2 = b;
	b2.printStack();


	cout << "\n\n\nПроверка на double" << endl;
	Stack <double> c;
	c + 3.4 + 5.10 + 10.13 + 13.25 + 2.10;
	--c;
	if (c())
		c.printStack();
	else
		cout << "Стек пустой";

	cout << "\n\nПроверка операции присваивания для double" << endl;
	Stack <double> c2;
	c2 = c;
	c2.printStack();
	return 0;
}