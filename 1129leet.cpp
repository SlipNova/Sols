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

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<vector<int>> dist(n, vector<int>(2, -1));
    vector<vector<int>> adjr(n), adjb(n);
    for (auto e : redEdges) {
        adjr[e[0]].push_back(e[1]);
    }
    for (auto e : blueEdges) {
        adjb[e[0]].push_back(e[1]);
    }
    queue<pair<int,int>> q;
    dist[0][0] = 0;
    dist[0][1] = 0;
    q.push({0, 0});
    q.push({0, 1});
    while (!q.empty()) {
        auto [curr, red] = q.front();
        q.pop();
        if (red) {
            for (auto it : adjb[curr]) { 
                if (dist[it][0] == -1) {
                    dist[it][0] = dist[curr][1] + 1;
                    q.push({it, 0});
                }
            }
        }
        else {
            for (auto it : adjr[curr]) {
                if (dist[it][1] == -1) {
                    dist[it][1] = dist[curr][0] + 1;
                    q.push({it, 1});
                }
            }
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (dist[i][0] == -1) {
            ans[i] = dist[i][1];
        }
        else if (dist[i][1] == -1) {
            ans[i] = dist[i][0];
        }
        else {
            ans[i] = min(dist[i][0], dist[i][1]);
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
        int n, r, b;
        cin >> n >> r >> b;
        vector<vector<int>> redEdges(r, vector<int>(2)), blueEdges(b, vector<int>(2));
        for (int i = 0; i < r; i++) cin >> redEdges[i][0] >> redEdges[i][1];
        for (int i = 0; i < b; i++) cin >> blueEdges[i][0] >> blueEdges[i][1];
        vector<int> ans = shortestAlternatingPaths(n, redEdges, blueEdges);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}