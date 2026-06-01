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



int minimumCost(vector<int>& c) {
    sort(c.begin(), c.end(), greater<int>());
    int cost = 0;
    for (int i = 0; i < c.size(); i++) {
        if (i % 3 == 2)
            continue;
        cost += c[i];
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];
        cout << minimumCost(c) << '\n';
    }
    return 0;
}