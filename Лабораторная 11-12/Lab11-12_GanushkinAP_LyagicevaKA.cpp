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

	void operator +(T value)
	{
		stackPtr[top] = value;
		top--;
	}

	Stack& operator =(const Stack& other)
	{
		stackPtr = new T[other.size];
		for (int i = 0; i < size; i++)
			{
				stackPtr[i] = other.stackPtr[i];
			}
		return *this;
	}

	T& operator --()
	{
		top++;
		T value = stackPtr[top];
		stackPtr[top] = stackPtr[top - 1];
		return value;
	}

	bool empty()
	{
		if (top != size - 1) 
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	void printStack() {
		for (int i = top + 1; i < size; i++)
			cout << stackPtr[i] << endl;

	};
	
	
};


int main()
{
	setlocale(LC_ALL, "rus");
	Stack <int> a;
	a + 3;
	a + 5;
	a + 10;
	a + 2222;
	--a;
	a.printStack();
	return 0;
}