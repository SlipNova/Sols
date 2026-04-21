#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

template <typename T>
class UnionFind {
    unordered_map<T, T> parent;
    unordered_map<T, int> rank;
public:
    UnionFind() {}

    void add(const T& _ele) {
        if (parent.find(_ele) == parent.end()) {
            parent[_ele] = _ele;
            rank[_ele] = 1;
        }
    }

    T find(const T& _ele) {
        if (parent[_ele] != _ele) {
            parent[_ele] = find(parent[_ele]);
        }
        return parent[_ele];
    }

    void unite(const T& P, const T& Q) {
        T rootP = find(P);
        T rootQ = find(Q);
        if (rootP != rootQ) {
            if (rank[rootP] > rank[rootQ]) {
                parent[rootQ] = rootP;
            }
            else if (rank[rootP] < rank[rootQ]) {
                parent[rootP] = rootQ;
            }
            else {
                parent[rootQ] = rootP;
                rank[rootP] += 1;
            }
        }
    }
};

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

int minimumHammingDistance1(vector<int>& a, vector<int>& b, vector<vector<int>>& cs) {
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

int minimumHammingDistance(vector<int>& a, vector<int>& b, vector<vector<int>>& cs) {
    int n = a.size();
    UnionFind<int> uf;
    for (int i = 0; i < n; i++) {
        uf.add(i);
    }
    for (auto& x : cs) {
        uf.unite(x[0], x[1]);
    }
    unordered_map<int, vector<int>> groups;
    for (int i = 0; i < n; i++) {
        int root = uf.find(i);
        groups[root].push_back(i);
    }
    int dist = 0;
    for (auto& [root, comp] : groups) {
        unordered_map<int, int> freq;
        for (int idx : comp) {
            freq[a[idx]]++;
        }
        for (int idx : comp) {
            if (freq[b[idx]] > 0) {
                freq[b[idx]]--;
            } else {
                dist++;
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