// Acknowledgement : Prof. Downing at UT-Austin OOP Lecture

#include <cassert>  // assert
#include <iostream> // cout, endl

int f () {
    int i = 2;
    return i;}

int* g () {
    int j = 2;
    return &j;}       // warning: address of local variable 'j' returned

int& h () {
    int k = 2;
    return k;}        // warning: reference to local variable 'k' returned

int main () {
    using namespace std;
    cout << "FunctionReturns.c++" << endl;

    {
    int v = f();
    assert(v == 2);
    }

    {
    int* p = g();
    assert(*p == 2); // ?
    }

    {
    int& r = h();
    assert(r == 2);  // ?
    }

    cout << "Done." << endl;
    return 0;
}
