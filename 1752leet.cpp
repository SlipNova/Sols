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

bool check(vector<int>& a) {
    int n = a.size();
    int sm = INT_MAX;
    int id = -1;
    for (int i = 0; i < n; i++) {
        sm = min(sm, a[i]);
        if (sm == a[i])
            id = i;
        while (i + 1 < n && a[i] == a[i + 1]) {
            i++;
        }
    }
    for (int i = id; i < n - 1; i++) {
        if (a[i] > a[i + 1])
            return false;
    }
    if (id == 0)
        return true;
    if (a[n - 1] > a[0])
        return false;
    for (int i = 0; i < id - 1; i++) {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << (check(a) ? "Yes" : "No") << '\n';
    }
    return 0;
}