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
        int n; cin >> n;
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            if (i % 2 == 0) {
                a[i].second = 0;
            }
            else {
                a[i].second = 1;
            }
        }
        sort(a.begin(), a.end());
        string ans = "YES";
        for (int i = 0; i < n - 1; i++) {
            if (a[i].second == a[i + 1].second) {
                ans = "NO";
                break;
            }
        }        
        cout << ans << '\n';
    }
    return 0;
}