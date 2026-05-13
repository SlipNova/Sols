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


vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> ans = grid;
    int layers = min(m, n) / 2;
    for (int l = 0; l < layers; l++) {
        vector<int> v;
        int top = l, bottom = m - 1 - l;
        int left = l, right = n - 1 - l;
        for (int j = left; j <= right; j++)
            v.push_back(grid[top][j]);
        for (int i = top + 1; i <= bottom; i++)
            v.push_back(grid[i][right]);
        for (int j = right - 1; j >= left; j--)
            v.push_back(grid[bottom][j]);
        for (int i = bottom - 1; i > top; i--)
            v.push_back(grid[i][left]);

        int len = v.size();
        int shift = k % len;
        int idx = shift;
        for (int j = left; j <= right; j++) {
            ans[top][j] = v[idx % len];
            idx++;
        }
        for (int i = top + 1; i <= bottom; i++) {
            ans[i][right] = v[idx % len];
            idx++;
        }
        for (int j = right - 1; j >= left; j--) {
            ans[bottom][j] = v[idx % len];
            idx++;
        }
        for (int i = bottom - 1; i > top; i--) {
            ans[i][left] = v[idx % len];
            idx++;
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
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> a(m, vector<int> (n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin  >> a[i][j];
            }
        }
        vector<vector<int>> ra = rotateGrid(a, k);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << ra[i][j] << (j == n - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}