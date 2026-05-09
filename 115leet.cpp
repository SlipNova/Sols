#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}


int numDistinct(string s, string t) {
    int sl = s.length();
    int tl = t.length();
    if (tl > sl)
        return 0;
    vector<vector<ull>> dp(tl, vector<ull>(sl, 0));
    dp[0][0] = (s[0] == t[0] ? 1 : 0);
    for (int j = 1; j < sl; j++) {
        if (s[j] == t[0]) {
            dp[0][j] = dp[0][j - 1] + 1;
        } else {
            dp[0][j] = dp[0][j - 1];
        }
    }
    for (int j = 1; j < sl; j++) {
        for (int i = 1; i < tl; i++) {
            if (i > j)
                continue;
            dp[i][j] = dp[i][j - 1];
            if (s[j] == t[i]) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }
    return dp[tl - 1][sl - 1];
}

int numDistinct(string s, string t) {
    vector<int> dp(t.size() + 1, 0);
    dp[0] = 1;
    for (char c : s) {
        for (int i = t.size() - 1; i >= 0; i--) {
            if (c == t[i]) {
                dp[i + 1] += dp[i];
            }
        }
    }

    return dp[t.size()];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    tt = 1;
    while (tt--) {
        string s, t;
        cin >> s >> t;
        cout << numDistinct(s, t) << '\n';
    }
    return 0;
}