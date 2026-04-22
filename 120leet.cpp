#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    for (int i = 1; i < n; i++) {
        int c = triangle[i].size();
        for (int j = 0; j < c; j++) {
            if (j == 0) {
                triangle[i][j] += triangle[i - 1][j];
                continue;
            }
            if (j == c - 1) {
                triangle[i][j] += triangle[i - 1][j - 1];
                continue;
            }
            triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < triangle[n - 1].size(); i++) {
        ans = min(ans, triangle[n - 1][i]);
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
        vector<vector<int>> a(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                a[i].resize(i + 1);
                cin >> a[i][j];
            }
        }
        cout << minimumTotal(a) << '\n';
    }
    return 0;
}