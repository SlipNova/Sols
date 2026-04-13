#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

const int inf = INT_MAX;

int dist(int x, int y) {
    int x1 = x / 6;
    int x2 = x % 6;
    int y1 = y / 6;
    int y2 = y % 6;
    return abs(x1 - y1) + abs(x2 - y2);
}

int minimumDistance(string word) {
    int n = word.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(26, vector<int>(26, inf)));
    int fw = word[0] - 'A';
    for (int i = 0; i < 26; i++) {
        dp[0][fw][i] = 0;
        dp[0][i][fw] = 0;
    }
    for (int k = 1; k < n; k++) {
        int w = word[k] - 'A';
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                int val = dp[k - 1][i][j];
                if (val == inf) continue;
                int ld = dist(w, i);
                int rd = dist(w, j);
                dp[k][w][j] = min(dp[k][w][j], val + ld);
                dp[k][i][w] = min(dp[k][i][w], val + rd);
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            ans = min(ans, dp[n - 1][i][j]);
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
        string str;
        cin >> str;
        cout << minimumDistance(str) << '\n';
    }
    return 0;
}