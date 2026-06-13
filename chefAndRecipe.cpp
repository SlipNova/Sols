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
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        unordered_set<int> st, seen;
        string ans = "YES";
        int id = 0;
        while (id < n) {
            int cnt = 1;
            if (seen.contains(a[id])) {
                ans = "NO";
                break;
            }
            else {
                seen.insert(a[id]);
            }
            while (id + 1 < n && a[id] == a[id + 1]) {
                cnt++;
                id++;
            }
            if (st.contains(cnt)) {
                ans = "NO";
                break;
            }
            else {
                st.insert(cnt);
            }
            id++;
        }
        cout << ans << '\n';
    }
}
