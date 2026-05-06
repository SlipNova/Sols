#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            grid[j][m - i - 1] = box[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        int id = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (grid[i][j] == '*') {
                id = i - 1;
            }
            else if (grid[i][j] == '#') {
                if (i != id) swap(grid[i][j], grid[id][j]);
                id--;
            }
        }
    }
    return grid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, n;
        cin >> m >> n;
        vector<vector<char>> grid(m, vector<char>(n)), sol;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        sol = rotateTheBox(grid);
        for (int i = 0; i < sol.size(); i++) {
            for (int j = 0; j < sol[0].size(); j++) {
                cout << sol[i][j] << (j == sol[0].size() - 1 ?  : ' ');
            }
            cout << '\n';
        }
    }
    return 0;
}