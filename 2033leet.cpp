#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int minOperations1(vector<vector<int>>& a, int x) {
    int m = a.size();
    int n = a[0].size();
    int ans = -1;
    vector<int> c;
    int k = a[0][0] % x;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % x != k) return ans;
            c.push_back(a[i][j]);
        }
    }
    sort(c.begin(), c.end());
    ans = 0;
    int mid = c[c.size() / 2];
    for (int i = 0; i < c.size(); i++) {
        ans += abs(c[i] - c[mid]) / x;
    }
    return ans;
}

int minOperations(vector<vector<int>>& a, int x) {
    int m = a.size();
    int n = a[0].size();
    int ans = -1;
    vector<int> c;
    int k = a[0][0] % x;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % x != k)
                return ans;
            c.push_back(a[i][j]);
        }
    }
    nth_element(c.begin(), c.begin() + c.size() / 2, c.end());
    int mid = c[c.size() / 2];
    ans = 0;
    for (int i = 0; i < c.size(); i++) {
        ans += abs(c[i] - mid) / x;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, n, x;
        cin >> m >> n >> x;
        vector<vector<int>> a(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        cout << minOperations(a, x) << '\n';
    }
    return 0;
}