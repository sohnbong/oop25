#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v = {4, 1, 3, 5, 2, 3, 1, 7};
	
	for (auto x: v) cout << x << " ";
	cout << endl;

	sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
	{
            return a > b;
	});

	for (auto x: v) cout << x << " ";
	cout << endl;

	return 0;
}

