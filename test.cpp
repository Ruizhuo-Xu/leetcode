#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a = {1, 2, 3};
	int i = 2;
	cout << a[i--] << endl;
	cout << a[i] << endl;
	return 0;
}