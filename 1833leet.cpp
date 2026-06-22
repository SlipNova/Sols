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

int maxIceCream(vector<int>& cost, int coins) {
    int mx = -1;
    int n = cost.size();
    for (int i = 0; i < n; i++) {
        mx = max(mx, cost[i]);
    }
    vector<int> a(mx + 1, 0);
    for (int i = 0; i < n; i++) {
        a[cost[i]]++;
    }
    int ans = 0;
    for (int i = 1; i < mx + 1; i++) {
        if (a[i] == 0)
            continue;
        int x = coins / i;
        if (x > a[i]) {
            coins -= a[i] * i;
            ans += a[i];
        } else {
            coins -= x * i;
            ans += x;
            break;
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
        int n, coins;
        cin >> n >> coins;
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        cout << maxIceCream(c, coins) << '\n';
    }
    return 0;
}