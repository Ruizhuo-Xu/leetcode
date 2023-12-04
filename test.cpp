#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a = {1, 2, 3};
	vector<int> b = {1, 2, 4};
	if (a == b) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	return 0;
}