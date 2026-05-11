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

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    if (k - (n * (n + 1)) / 2 < 0) {
        cout << - 1 << '\n';
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        cout << 1 << ' ';
    }
    cout << (ll) k - (n + 2) * (n - 1) / 2 << '\n';
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}