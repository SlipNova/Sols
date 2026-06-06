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

vector<int> leftRightDifference(vector<int>& a) {
    int n = a.size();
    vector<int> s(n, 0);
    s[0] = a[0];
    for (int i = 1; i < n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    vector<int> ans(n);
    ans[0] = abs(s[n - 1] - a[0]);
    for (int i = 1; i < n; i++) {
        ans[i] = abs(s[n - 1] - s[i - 1] - s[i]);
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), ans;
        for (int i = 0; i < n; i++) cin >> a[i];
        ans = leftRightDifference(a);
        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i != n - 1 ? ' ' : '\n');
        }
    }
    return 0;
}