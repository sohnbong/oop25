// C++ program to demonstrate working of functors.
#include <iostream>
#include <algorithm>
using namespace std;
 
// A Functor
class increment
{
private:
    int num;
public:
    increment(int n=1) : num(n) {  }
 
    // This operator overloading enables calling
    // operator function () on objects of increment
    int operator () (int arr_num) const {
        return num + arr_num;
    }
};
 
// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int to_add = 5;
 
    transform(arr, arr+n, arr, increment());
 
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n\n\n";
    increment myfunctor(3);
    cout << "myfunctor(11): " << myfunctor(11) << endl;
    return 0;
}
