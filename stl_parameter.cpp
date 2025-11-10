// vector/vector-average.cpp - Averages numbers in vector
// Fred Swartz - 2003-11-20

#include <vector>
#include <iostream>
using namespace std;

float sum(const vector<float>& x); // prototype

//====================================================== main
int main() {
    vector<float> a;   // Declare a vector.

    float temp;
    while (cin >> temp) {
        a.push_back(temp);
    }
    
    cout << "Average = " << sum(a)/a.size() << endl;
    
    return 0;
}


//======================================================= sum
// sum adds the values of the vector it is passed.
float sum(const vector<float>& x) {
    float total = 0.0;  // the sum is accumulated here
    for (int i=0; i<x.size(); i++) {
        total = total + x[i];  
    }
    return total;
}


