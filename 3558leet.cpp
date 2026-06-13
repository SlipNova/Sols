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

int assignEdgeWeights(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    int mx = 0;
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    while (!q.empty()) {
        auto [f, d] = q.front();
        mx = max(d, mx);
        q.pop();
        for (auto& neigh : adj[f]) {
            if (!visited[neigh]) {
                q.push({neigh, d + 1});
                visited[neigh] = true;
            }
        }
    }
    int ans = 1;
    mx--;
    while (mx--) {
        ans = (1ll * ans * 2) % MOD;
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
        vector<vector<int>> e(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> e[i][0] >> e[i][1];
        }
        cout << assignEdgeWeights(e) << '\n';
    }
    return 0;
}