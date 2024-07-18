#include <iostream>
#include <vector>
using namespace std;

int completeBag(vector<int>& weights, vector<int>& values, int bagSize) {
    vector<int> dp(bagSize + 1, 0);
    for (int i = 0; i < weights.size(); i++) {
        for (int j = weights[i]; j <= bagSize; j++) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[bagSize];
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> weights(m, 0);
    vector<int> values(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> weights[i] >> values[i];
    }
    int res = completeBag(weights, values, n);
    cout << res << endl;
    return 0;
}