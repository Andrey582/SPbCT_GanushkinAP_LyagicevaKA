template <typename T>
class Stack 
{
private:
	T* stackPtr;
	int size;
	T top;
public:
	Stack(int = 10);
	Stack(int size) {
		size > 0 ? size : 10;
		stackPtr = new T[size];
		top = -1;
	}
	~Stack() {
		delete[] stackPtr;
	};
	bool push(const T value) {
		if (top == size - 1)
			return false;
		top++;
		stackPtr[top] = value;
		return true;
	};
	bool pop() {
		if (top == size - 1)
			return false;
		stackPtr[top] = 0;
		top--;
		return false;
	}
	void printStack() {
		for (int ix = size - 1; ix >= 0; i--)
			cout << "|" << setw(4) << stackPtr[ix] << endl;

	};
};