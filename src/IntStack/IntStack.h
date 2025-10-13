#include <iostream>

const unsigned int DEFAULT_SIZE = 256;

class TIntStack {
public :
	TIntStack(unsigned int stackSize = DEFAULT_SIZE);
	TIntStack(const TIntStack& that); // Copy Constructor
	TIntStack& operator=(const TIntStack& assign); // Assignment Operator
	~TIntStack(); // Destructor

	void Push(int thisValue);
	int Pop();
	unsigned int HowMany() const;

private :
	int* _sp;
	unsigned int _count;
	unsigned int _size;
	void CountIncrement() { _count++; }
	void CountDecrement() { _count--; }
};
