#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

vector<pair<int,int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int sx, int sy) {
    int m = grid.size();
    int n = grid[0].size();
    stack<tuple<int, int, int, int>> st;
    st.push({sx, sy, -1, -1});
    visited[sx][sy] = true;
    while (!st.empty()) {
        auto [x, y, px, py] = st.top();
        st.pop();
        for (auto& it: dir) {
            int currx, curry;
            currx = x + it.first;
            curry = y + it.second;
            if (currx < 0 || curry < 0 || currx >= m || curry >= n) continue;
            if (grid[currx][curry] != grid[x][y]) continue;
            if (!visited[currx][curry]) {
                visited[currx][curry] = true;
                st.push({currx, curry, x, y});
            }
            else {
                if (currx != px && curry != py) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool containsCycle(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool> (n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                if (dfs(grid, visited, i, j)) return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, n;
        cin >> m >> n;
        vector<vector<char>> a(m, vector<char> (n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        cout << (containsCycle(a) ? "True" : "False") << '\n';
    }
    return 0;
}