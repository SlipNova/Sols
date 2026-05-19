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


int minimumEffort(vector<vector<int>>& a) {
    int n = a.size();
    auto compare = [](const vector<int>& f, const vector<int>& s) {
        int f1 = f[1] - f[0];
        int s1 = s[1] - s[0];
        return f1 > s1;
    };
    sort(a.begin(), a.end(), compare);
    int total = 0;
    int have = 0;
    for (int i = 0; i < n; i++) {
        int need = a[i][1];
        if (need > have) {
            total += (need - have);
            have = need - a[i][0];
        } else {
            have -= a[i][0];
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1];
        }
        cout << minimumEffort(a) << '\n';
    }
    return 0;
}