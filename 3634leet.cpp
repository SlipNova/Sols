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



int minRemoval(vector<int>& a, int k) {
    int n = a.size();
    sort(a.begin(), a.end());
    int r = 0, ans = n;
    for (int l = 0; l < n; l++) {
        while (r < n && a[r] <= 1ll * k * a[l]) {
            r++;
        }
        ans = min(ans, n - (r - l));
    } 
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << minRemoval(a, k) << '\n';
    }
    return 0;
}