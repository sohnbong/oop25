// Acknowledgement : Prof. Downing at UT-Austin OOP Lecture

#include <cassert>  // assert
#include <iostream> // cout, endl

void f (int v, int* p, int& r) {
    ++v;
    ++(*p);
    ++r;
}

int main () {
    using namespace std;
    cout << "FunctionArguments.c++" << endl;

    int i = 2;
    int j = 2;
    int k = 2;
    f(i, &j, k);
    assert(i == 2);
    assert(j == 3);
    assert(k == 3);

    cout << "Done." << endl;
    return 0;
}
