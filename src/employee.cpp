#include <iostream>

using namespace std;

class Employee
{
	int salary;

public:
	Employee() { salary=0; }
	~Employee() {}
	int getSalary() { return salary; }
	void setSalary(int s) { salary=s; }
	void addSalary(int s) { salary+=s; }
};

// inheritance : Manager inherits all members of Employee
// is-a relationship : "Manager is an Employee"
class Manager : public Employee
{
	int bonus;

public:
	Manager() { bonus=0; }
	~Manager() {}
	int getBonus() { return bonus; }
	void setBonus(int b) { bonus=b; }
	void addSalary(int s) { setSalary(getSalary()+s); bonus+=s*0.1; } // assume bonus is 10% increased when salary is increased.
};

int main()
{
	Employee x;
	Manager y;
	y.setBonus(1000);
	x.setSalary(1000);
	y.setSalary(2000);
	x.addSalary(500);
	y.addSalary(1000);
	cout << "x salary:" << x.getSalary() << "\n";
	cout << "y salary:" << y.getSalary() << "\n";
	cout << "y bonus:" << y.getBonus() << "\n";

	return 0;
}


