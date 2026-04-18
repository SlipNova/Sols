#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

const vector<vector<int>> dir = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int> (n, 1));
    vector<tuple<int, int, int>> c;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c.push_back({matrix[i][j], i, j});
        }
    }
    sort(c.begin(), c.end());
    for (auto& [val, i, j] : c) {
        for (int z = 0; z < 4; z++) {
            int currx, curry;
            currx = dir[z][0] + i;
            curry = dir[z][1] + j;
            if (currx < 0 || curry < 0 || currx > m - 1 || curry > n - 1) continue;
            if (matrix[currx][curry] < val) {
                dp[i][j] = max(dp[i][j], dp[currx][curry] + 1);
            }
        }
    }
    int ans = 0;
    for (auto& it : dp) {
        for (auto& j: it) {
            ans = max(ans, j);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int> (n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        cout << longestIncreasingPath(matrix) << '\n';
    }
    return 0;
}