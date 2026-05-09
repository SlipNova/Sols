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

int maxPoints(vector<vector<int>>& a) {
    int n = a.size();
    if (n <= 2) return n;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        unordered_map<pair<int, int>, int, PairHash> mp;
        for (int j = i + 1; j < n; j++) {
            int dx = a[j][0] - a[i][0];
            int dy = a[j][1] - a[i][1];
            int g = gcd(abs(dx), abs(dy));
            dx /= g;
            dy /= g;
            if (dx < 0) {
                dx *= -1;
                dy *= -1;
            }
            if (dx == 0) dy = 1;
            if (dy == 0) dx = 1;
            mp[{dx, dy}]++;
            ans = max(ans, mp[{dx, dy}] + 1);
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
        int n;
        cin >> n; 
        vector<vector<int>> a(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> a[i][j];
            }
        }
        cout << maxPoints(a) << '\n';
    }
    return 0;
}