#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int maxLen = 50005;
    vector<int> f(maxLen);
    vector<int> a(maxLen);
    vector<char> s(maxLen);
    s[0] = '9';
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> s[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if (s[i - 1] < '2' && s[i] < '7') {
            f[i] = (long long)(f[i] + f[i - 2]) % MOD;
        }
    }
    cout << f[n] << endl;
    return 0;
}