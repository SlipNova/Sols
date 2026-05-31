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

bool asteroidsDestroyed(int mass, vector<int>& a) {
    int n = a.size();
    unsigned long long l = mass;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (l >= a[i]) {
            l += 1ULL * a[i];
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int mass, n;
        cin >> mass >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << (asteroidsDestroyed(mass, a) ? "Yes" : "No") << '\n';
    }
    return 0;
}