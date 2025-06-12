#include <bits/stdc++.h>
typedef long long ll;
int M = 1e9 + 7;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    prev[0] = (grid[0][0] != '*');

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                curr[j] = 0;
            } else {
                if (i == 0 && j == 0) {
                    curr[j] = 1;
                } else {
                    curr[j] = 0;
                    if (i > 0) curr[j] = (curr[j] + prev[j]) % M;
                    if (j > 0) curr[j] = (curr[j] + curr[j-1]) % M;
                }
            }
        }
        prev = curr;
    }

    cout << prev[n-1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
