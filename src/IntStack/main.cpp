#include <iostream>
#include "IntStack.h"

using namespace std;

void PrintStack(TIntStack thisOne)
{
	unsigned int i = thisOne.HowMany();
	cout << "----------------------------------\n";
	for (int j=0; j < i; j++) 
		cout << "[" << thisOne.Pop() << "]" << endl;	
}

int main()
{
	int i;

	TIntStack a;
	TIntStack b(20);
	TIntStack *ip = new TIntStack;

	for (i=1; i <= 5; i++) {
		a.Push(i);
		b.Push(-i);
	}

	a=b;
	TIntStack c = b;

cout << "a:";
	PrintStack(a);
cout << "b:";
	PrintStack(b);
cout << "c:";
	PrintStack(c);
cout << "*ip:";
	PrintStack(*ip);

	delete ip;

	return 0;
}

