#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

const vector<vector<int>> dir = {{1, 0}, {0, 1}};

int maxPathScore(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
    int sc = (grid[0][0] == 0 ? 0 : 1);
    if (sc <= k) {
        dp[0][0][sc] = grid[0][0];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int cc = (grid[i][j] == 0 ? 0 : 1);
            for (int c = 0; c < k + 1; c++) {
                if (dp[i][j][c] == -1) continue;
                if (i + 1 < m) {
                    int nc = c + (grid[i + 1][j] == 0 ? 0 : 1);
                    if (nc <= k) {
                        dp[i + 1][j][nc] = max(dp[i + 1][j][nc], dp[i][j][c] + grid[i + 1][j]);
                    }
                }
                if (j + 1 < n) {
                    int nc = c + (grid[i][j + 1] == 0 ? 0 : 1);
                    if (nc <= k) {
                        dp[i][j + 1][nc] = max(dp[i][j + 1][nc], dp[i][j][c] + grid[i][j + 1]);
                    }
                }
            }
        }
    }
    int ans = -1;
    for (int c = 0; c < k + 1; c++) {
        ans = max(ans, dp[m - 1][n - 1][c]);
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt; cin >> tt;
    while (tt--) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        cout << maxPathScore(grid, k) << '\n';
    }
    return 0;
}