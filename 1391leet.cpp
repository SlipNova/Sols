#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}


const vector<vector<pair<int, int>>> dir = {{{0, 1}, {0, -1}}, {{1, 0}, {-1, 0}}, {{0, -1}, {1, 0}}, {{0, 1}, {1, 0}}, {{0, -1}, {-1, 0}}, {{-1, 0}, {0, 1}} };

bool connects(vector<vector<int>>& grid, int x, int y, int px, int py) {
    for (auto& [dx, dy]: dir[grid[x][y] - 1]) {
        if (x + dx == px && y + dy == py) {
            return true;
        }
    }
    return false;
}

bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    int m = grid.size();
    int n = grid[0].size();
    stack<pair<int,int>> st;
    st.push({x, y});
    visited[x][y] = true;
    while (!st.empty()) {
        auto [cx, cy] = st.top();
        if (cx == m - 1 && cy == n - 1) return true;
        st.pop();
        for (auto& it: dir[grid[cx][cy] - 1]) {
            int nx = it.first + cx;
            int ny = it.second + cy;
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;
            if (connects(grid, nx, ny, cx, cy)) {
                st.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return false;
}

bool hasValidPath(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    return dfs(grid, visited, 0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        cout << (hasValidPath(grid) ? "True" : "False") << '\n';
    }
    return 0;
}