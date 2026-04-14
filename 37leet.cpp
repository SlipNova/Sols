#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

bool isValid(vector<vector<char>>& board, int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] - '0' == val && i != col)
            return false;
        if (board[i][col] - '0' == val && i != row)
            return false;
    }
    int bc, br;
    if (col < 3) {
        bc = 0;
    } else if (col < 6) {
        bc = 3;
    } else {
        bc = 6;
    }
    if (row < 3) {
        br = 0;
    } else if (row < 6) {
        br = 3;
    } else {
        br = 6;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int a = br + i;
            int b = bc + j;
            if (a == row && b == col)
                continue;
            if (board[a][b] - '0' == val)
                return false;
        }
    }
    return true;
}

bool start(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') continue;
            for (int g = 1; g < 10; g++) {
                if (isValid(board, i, j, g)) {
                    board[i][j] = '0' + g;
                    if (start(board)) return true;
                    board[i][j] = '.';
                }
            }
            return false;
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    start(board);
}

void SOLVE(vector<vector<char>>& board) {
    vector<pair<int, int>> need;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') continue;
            need.push_back({i, j});
        }
    }
    int n = need.size();
    int idx = 0;
    stack<vector<int>> st; 
    while (idx >= 0 && idx < n) {
        auto [f, s] = need[idx];
        int ini = 1;
        if (!st.empty() && st.top()[0] == idx) {
            ini = st.top()[1] + 1;
            st.pop();
        }
        bool ok = false;
        for (int g = ini; g <= 9; g++) {
            if (isValid(board, f, s, g)) {
                board[f][s] = '0' + g;
                st.push({idx, g});
                ok = true;
                idx++;
                break;
            }
        }
        if (!ok) {
            board[f][s] = '.';
            idx--;
            if (idx >= 0) {
                auto [a, b] = need[idx];
                board[a][b] = '.';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        vector<vector<char>> board(9, vector<char>(9, 'i'));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> board[i][j];
            }
        }
        solveSudoku(board);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
                if (j < 8) cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}