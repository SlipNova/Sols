#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<long long>()(((long long)p.first << 32) ^ p.second);
    }
};


int dfs(int i, vector<int>& a, vector<int>& dp, int d) {
    int n = a.size();
    if (dp[i] != -1) return dp[i];
    dp[i] = 1;
    for (int j = i + 1; j <= min(n - 1, i + d); j++) {
        if (a[i] <= a[j]) break;
        dp[i] = max(dp[i], 1 + dfs(j, a, dp, d));
    }
    for (int j = i - 1; j >= 0 && j >= i - d; j--) {
        if (a[j] >= a[i]) break;            
        dp[i] = max(dp[i], 1 + dfs(j, a, dp, d));
    }
    return dp[i];
}

int maxJumps(vector<int>& a, int d) {
    int n = a.size();
    vector<int> dp(n, -1);
    int sol = 1;
    for (int i = 0; i < n; i++) {
        sol = max(sol, dfs(i, a, dp, d));
    }
    return sol;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, d;
        cin >> n, d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << maxJumps(a, d) << '\n';
    }
    return 0;
}