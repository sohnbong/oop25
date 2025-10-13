#include <iostream>
#include <stdlib.h>
#include "IntStack.h"

using namespace std;

TIntStack::TIntStack(unsigned int stackSize /* = DEFAULT_SIZE */ )
{
	cout << "Typical Constructor Called! \n";
	if (stackSize > 0) {
		_size = stackSize;
		_sp = new int[_size];
		for (int i = 0 ; i < _size ; i++) _sp[i] = 0;
	} else {
		_sp = 0;
		_size = 0;
	}

	_count = 0;
}

TIntStack::TIntStack(const TIntStack& source)
{
	cout << "Copy Constructor Called! \n";
	_size = source._size;
	if (_size > 0) {
		_sp = new int[_size];
		_count = source._count;
		for (int i=0; i < _count; ++i) _sp[i] = source._sp[i];
	} else {
		_sp = 0;
		_count = 0;
	}
}

TIntStack::~TIntStack()
{
	cout << "Executing the destructor for TIntStack\n";
	delete [] _sp;
}

TIntStack& TIntStack::operator=(const TIntStack& source)
{
	cout << "Operator Assignment Called! \n";
	if (this == &source) {
		cout << "Warning : Assignment to self.\n";
		return *this;
	}

	if (source._count > this->_size) {
		delete [] _sp;
		this->_size = source._size;
		_sp = new int [this->_size];
	}

	for (int i=0; i < source._count; i++) this->_sp[i] = source._sp[i];
	this->_count = source._count;

	return *this;
}

void TIntStack::Push(int what)
{
	if (_count < _size) {
		_sp[_count] = what;
		CountIncrement(); // _count++;
	} else {
		cout << "Stack is FULL. Cannot Push value" << what << endl;
	}
}

int TIntStack::Pop()
{
	if (_count <= 0) {
		cout << "Stack is EMPTY\n";
		exit (1);
	}
	CountDecrement();  // _count--;
	return _sp[_count];
}

unsigned TIntStack::HowMany() const
{
	return _count;
}

