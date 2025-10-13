#include <iostream>

using namespace std;

template<typename T> 
class Stack { 
public: 
    Stack(int = 100); 
    ~Stack();
    bool push(const T&);
    bool pop(T&);
    bool isEmpty() const;
    bool isFull() const;    

private: 
    int size; 
    int top; 
    T *stackPtr;
};

template<typename T> 
Stack<T>::Stack(int s)
{ stackPtr=new T[s]; }

template<typename T> 
Stack<T>::~Stack()
{ delete [] stackPtr; }

template<typename T> 
bool Stack<T>::push(const T& item)
{
	stackPtr[top++]=item;
	return true;
}

template<typename T> 
bool Stack<T>::pop(T& item)
{
	item = stackPtr[--top];
	return true;
}

template<typename T> 
bool Stack<T>::isEmpty() const
{
	if (top==0) return true;
	return false;
}

template<typename T> 
bool Stack<T>::isFull() const
{
	if (top>=size) return true;
	return false;
}

int main()
{
    int x, y;

    Stack<int> intStack(5);
    intStack.push(5);
    intStack.push(8);
    intStack.pop(x);
    intStack.pop(y);

    cout << x << endl;
    cout << y << endl;

    return 0;
}
