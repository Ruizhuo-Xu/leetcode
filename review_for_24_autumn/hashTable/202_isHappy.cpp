#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while (n != 1) {
            int sum = 0;
            while (n / 10) {
                sum += pow((n % 10), 2);
                n = n / 10;
            }
            sum += pow(n, 2);
            n = sum;
            if (st.find(n) != st.end()) {
                return false;
            }
            st.insert(n);
        }
        return true;
    }
};

int main() {
    cout << Solution().isHappy(18) << endl;
    return 0;
}
