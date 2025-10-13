#include <iostream>
#include <string>
using namespace std;

class point {
public:
   point(double x_in = 0.0, double y_in = 0.0): x(x_in), y(y_in) {}
   double get_x() { return x;} //returns the rvalue of x
   double get_y() { return y;}
   double& x_lv() { return x;} //returns an alias to x
   double& y_lv() { return y;}
private:
   double x, y;
};

int main()
{
   point a(2.5, -2.5), b(1.0, 1.0), c;

   cout << "lvalue-rvalue semantics\n";
   //compute the midpoint
   c.x_lv() = (a.get_x() + b.get_x()) / 2;
   c.y_lv() = (a.get_y() + b.get_y()) / 2;
   //notice you get the same output because
   //an lvalue is automatically dereferenced where
   //appropriate to give the rvalue
   cout << c.get_x() << ", " << c.get_y() << endl;
   cout << c.x_lv() << ", " << c.y_lv() << endl;
}

