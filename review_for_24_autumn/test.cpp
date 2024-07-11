#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> strs = {"AKL", "ABC", "CVT", "BGE"};
    sort(strs.begin(), strs.end());
    for (string str : strs) {
        cout << str << endl;
    }
    return 0;
}