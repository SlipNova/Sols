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

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order) {
    visited[node] = true;
    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            dfs(neigh, adj, visited, order);
        }
    }
    order.push_back(node);
}

vector<int> topSort(vector<vector<int>>& adj) {
    int nodes = adj.size();
    vector<bool> visited(nodes, false);
    vector<int> order;
    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, order);
        }
    }
    reverse(order.begin(), order.end());
    return order;
}

vector<vector<int>> getAncestors2(int nodes, vector<vector<int>>& edges) {
    vector<vector<int>> adj(nodes);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
    }
    vector<set<int>> a(nodes);
    vector<int> torder = topSort(adj);
    for (auto x : torder) {
        for (auto y : adj[x]) {
            a[y].insert(x);
            for (auto z : a[x]) {
                a[y].insert(z);
            }
        }
    }
    vector<vector<int>> ans(nodes);
    for (int i = 0; i < nodes; i++) {
        for (int it : a[i]) {
            ans[i].push_back(it);
        }
    }
    return ans;
}

vector<vector<int>> getAncestors(int nodes, vector<vector<int>>& edges) {
    vector<vector<int>> adj(nodes);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
    }
    vector<bitset<1001>> a(nodes);
    vector<int> torder = topSort(adj);
    for (int x : torder) {
        for (int y : adj[x]) {
            a[y][x] = 1;
            a[y] |= a[x];
        }
    }
    vector<vector<int>> ans(nodes);
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            if (a[i][j]) {
                ans[i].push_back(j);
            }
        }
    }
    return ans;
}

vector<vector<int>> getAncestors1(int nodes, vector<vector<int>>& edges) {
    vector<vector<int>> adj(nodes);
    for (auto& e : edges) {
        adj[e[1]].push_back(e[0]);
    }
    vector<vector<int>> ans(nodes);
    for (int node = 0; node < nodes; node++) {
        vector<bool> visited(nodes, false);
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto neigh : adj[curr]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    ans[node].push_back(neigh);
                    q.push(neigh);
                }
            }
        }
        sort(ans[node].begin(), ans[node].end());
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int nodes, m;
        cin >> nodes >> m;
        vector<vector<int>> edges(m, vector<int>(2)), ans;
        for (int i = 0; i < m; i++) {
            cin >> edges[i][0] >> edges[i][1];
        }
        ans = getAncestors(nodes, edges);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << (ans[i].size() - 1 == j ? '\n' : ' ');
            }
        }
    }
    return 0;
}