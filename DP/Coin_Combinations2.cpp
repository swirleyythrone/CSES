#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int MAX_X = 1e6 + 5;

int dp[MAX_X];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto &c : coins) cin >> c;

    dp[0] = 1;  // 1 way to make sum 0

    for (int i = 0; i < n; i++) {
        for (int sum = coins[i]; sum <= x; sum++) {
            dp[sum] = (dp[sum] + dp[sum - coins[i]]) % M;
        }
    }
    cout << dp[x] << '\n';
    return 0;
}
