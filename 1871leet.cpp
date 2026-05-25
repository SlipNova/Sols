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

bool canReach(string str, int a, int b) {
    int n = str.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int already = 0;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int i = max(front + a, already + 1); i <= min(front + b, n - 1);
             i++) {
            if (str[i] == '0' && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
        already = min(front + b, n - 1);
    }
    return visited[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        string str;
        cin >> str >> a >> b;
        cout << (canReach(str, a, b) ? "Yes" : "No") << '\n';
    }
    return 0;
}