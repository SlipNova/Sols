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

const int inf = INT_MAX;

int networkDelayTime(vector<vector<int>>& a, int n, int k) {
    vector<vector<pair<int,int>>> adj(n + 1);
    for (auto& it : a) {
        adj[it[0]].push_back({it[1], it[2]});
    }
    vector<int> dist(n + 1, inf);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[k] = 0;
    pq.push({0, k});
    while (!pq.empty()) {
        auto [d, curr] = pq.top();
        pq.pop();
        if (dist[curr] != d) continue;
        for (auto [v, c] : adj[curr]) {
            if (c + d < dist[v]) {
                dist[v] = c + d;
                pq.push({dist[v], v});
            }
        }
    }
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dist[i]);
    }
    if (mx == INT_MAX) mx = -1;
    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> a(m, vector<int>(3));
        for (int i = 0; i < m; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        cout << networkDelayTime(a, n, k) << '\n';
    }
    return 0;
}