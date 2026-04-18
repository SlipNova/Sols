#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int mirrorDistance(int n) {
    if (n == 0) return 0;
    int k = n;
    int sz = 1;
    while (k % 10 == 0) {
        k /= 10;
    }
    int l = k;
    int m = 0;
    while (l > 0) {
        l /= 10;
        sz *= 10;
    }
    sz /= 10;
    while (sz > 0) {
        m += k % 10 * sz;
        sz /= 10;
        k /= 10;
    }
    return abs(m - n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        cout << mirrorDistance(n) << '\n';
    }
    return 0;
}