#include <iostream>
#include <vector>
using namespace std;

int res = 0;
void backtracking(string s, int startIdx) {
    if (startIdx == s.size()) {
        res++;
        return ;
    }
    for (int i = startIdx; i < s.size(); i++) {
        string subS = s.substr(startIdx, i - startIdx + 1);
        if (stoi(subS) >= 1 && stoi(subS) <= 26) {
            backtracking(s, i + 1);
        }
    }
}


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    backtracking(s, 0);
    cout << res << endl;
    return 0;
}