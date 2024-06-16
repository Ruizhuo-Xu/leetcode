#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int right = s.size() - 1;
        for (int left = 0; left < right; left++, right--) {
            swap(s[left], s[right]);
        }
    }
};

int main() {
    vector<char> s = {'h','e','l','l','o'};
    Solution().reverseString(s);
    for (char c : s) {
        cout << c << ' ';
    }
    cout << endl;
    return 0;
}