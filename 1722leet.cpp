#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

void bfs(vector<vector<int>>& e, vector<bool>& visited, int node, vector<int>& comp) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        comp.push_back(f);
        for (auto& neigh : e[f]) {
            if (!visited[neigh]) {
                q.push(neigh);
                visited[neigh] = true;
            }
        }
    }
}

int minimumHammingDistance(vector<int>& a, vector<int>& b, vector<vector<int>>& cs) {
    int n = a.size();
    int c = cs.size();
    int dist = 0;
    vector<vector<int>> e(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < c; i++) {
        e[cs[i][0]].push_back(cs[i][1]);
        e[cs[i][1]].push_back(cs[i][0]);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> comp;
            bfs(e, visited, i, comp);
            unordered_map<int, int> freq;
            for (int j = 0; j < comp.size(); j++) {
                freq[a[comp[j]]]++;
            }
            for (int j = 0; j < comp.size(); j++) {
                if (freq[b[comp[j]]] > 0) {
                    freq[b[comp[j]]]--;
                }
                else {
                    dist++;
                }
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, a;
        cin >> n >> a;
        vector<int> source(n), target(n);
        vector<vector<int>> cs(a, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n; i++) {
                if (j == 0) {
                    cin >> source[i];
                }
                else {
                    cin >> target[i];
                }
            }
        }
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> cs[i][j];
            }
        }
        cout << minimumHammingDistance(source, target, cs) << '\n';
    }
    return 0;
}