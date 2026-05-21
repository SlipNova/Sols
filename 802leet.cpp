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

// unvisited, visiting, visited
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> ans;
    vector<int> state(n, 0);
    function<bool(int)> dfs = [&](int node) {
        if (state[node] == 1) return false;
        if (state[node] == 2) return true;
        state[node] = 1;
        for (auto neigh : graph[node]) {
            if (!dfs(neigh)) {
                return false;
            }
        }
        state[node] = 2;
        return true;
    };
    for (int i = 0; i < n; i++) {
        if (dfs(i)) {
            ans.push_back(i);
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
        int n;
        cin >> n;
        vector<vector<int>> graph;
        for (int i = 0; i < n; i++) {
            int m; cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> graph[i][j];
            }
        }
        vector<int> ans = eventualSafeNodes(graph);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}