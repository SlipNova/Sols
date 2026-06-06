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




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        ll x;
        cin >> n >> x;
        ll y = 0;
        ll s = INT_MIN;
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            y += 1ll * (b - 1) * a;
            ll need = 1ll * a * b - c;
            s = max(s, need);
        }
        if (x <= y) {
            cout << 0 << '\n';
        }
        else if (s <= 0) {
            cout << -1 << '\n';
        }
        else {
            cout << ((x - y + s - 1) / s) << '\n';
        }
        
    }
    return 0;
}