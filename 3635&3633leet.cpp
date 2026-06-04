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

int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
    int n = lst.size();
    int m = wst.size();
    int blt = 1e9;
    for (int i = 0; i < n; i++) {
        blt = min(blt, lst[i] + ld[i]);
    }
    int lw = 1e9;
    for (int j = 0; j < m; j++) {
        lw = min(lw, max(blt, wst[j]) + wd[j]);
    }
    int bwt = 1e9;
    for (int j = 0; j < m; j++) {
        bwt = min(bwt, wst[j] + wd[j]);
    }
    int wl = 1e9;
    for (int i = 0; i < n; i++) {
        wl = min(wl, max(bwt, lst[i]) + ld[i]);
    }
    return min(wl, lw);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> lst, ld, wst, wd;
        lst.resize(n);
        ld.resize(n);
        wst.resize(m);
        wd.resize(m);
        for (int i = 0; i < n; i++) {
            cin >> lst[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> ld[i];
        }
        for (int j = 0; j < m; j++) {
            cin >> wst[j];
        }
        for (int j = 0; j < m; j++) {
            cin >> wd[j];
        }
        cout << earliestFinishTime(lst, ld, wst, wd) << '\n';
    }
    return 0;
}