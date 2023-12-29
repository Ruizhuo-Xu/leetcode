#include <iostream>
#include <vector>
using namespace std;

int maxValue(int V, vector<int>& weights, vector<int>& values) {
    vector<int> dp(V + 1, 0);
    for (int i = 0; i < weights.size(); i++) {
        for (int j = weights[i]; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[V];
}

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> weights(N);
    vector<int> values(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i] >> values[i];
    }
    cout << maxValue(V, weights, values) << endl;
    return 0;
}