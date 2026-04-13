#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}


const vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dfs(vector<vector<char>>& board, string& word, int curr, int x, int y, int m, int n) {
    if (x < 0 || y < 0 || x >= m || y >= n) return false;
    if (board[x][y] != word[curr]) return false;
    if (curr == word.length() - 1) return true;
    char temp = board[x][y];
    board[x][y] = '#';
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (dfs(board, word, curr + 1, xx, yy, m, n)) {
            board[x][y] = temp;
            return true;
        }
    }
    board[x][y] = temp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(board, word, 0, i, j, m, n)) return true;
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
        string word; cin >> word;
        vector<vector<char>> board(m, vector<char>(n, ' '));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }
        cout << exist(board, word) ? cout << "Yes" : cout << "No" << '\n';
    }
    return 0;
}