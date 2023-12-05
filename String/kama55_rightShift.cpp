#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    cout << s << endl;
    return 0;
}