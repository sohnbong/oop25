// Acknowledgement : Prof. Downing at UT-Austin OOP Lecture

#include <cassert>  // assert
#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << "PointersVsReferences.c++" << endl;

    {
        int i = 2;
        int v = i;
        ++v;
        assert(i  == 2);
        assert(v  == 3);
        assert(&i != &v);
    }

    {
        int  j = 2;
        int* p = &j;
        ++*p;
        assert(j  == 3);
        assert(*p == 3);
        assert(p  == &j);
    }

    {
        int  k = 2;
        int& r = k;
        ++r;
        assert(k  == 3);
        assert(r  == 3);
        assert(&r == &k);
    }

    {
        int   l = 2;
        int*  p = &l;
        int*& r = p;
        ++*r;
        assert(l  == 3);
        assert(*p == 3);
        assert(*r == 3);
        assert(&r == &p);
    }

    cout << "Done." << endl;
    return 0;}

