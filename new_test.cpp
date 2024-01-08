#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "12";
    int x = stoi(s);
    cout << sizeof(x) << ' ' <<  stoi(s) << endl; // stirng->int
    cout << to_string(x) << endl; // int -> string
    return 0;
}
