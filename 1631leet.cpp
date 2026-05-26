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

const int inf = 1e9;

vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; 

int minimumEffortPath1(vector<vector<int>>& h) {
    int m = h.size();
    int n = h[0].size();
    auto cmp = [] (tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<0>(a) > get<0>(b);
    };
    vector<vector<int>> dist(m, vector<int>(n, inf));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> pq(cmp); 
    dist[0][0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        auto [d, x, y] = pq.top();
        pq.pop();
        if (dist[x][y] != d) continue;
        if (x == m - 1 && y == n - 1) return d;
        for (auto c : dir) {
            int nx = c[0] + x;
            int ny = c[1] + y;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            int val = abs(h[x][y] - h[nx][ny]);
            int ne = max(d, val);
            if (ne < dist[nx][ny]) {
                dist[nx][ny] = ne;
                pq.push({ne, nx, ny});
            }
        }
    }
    return dist[m - 1][n - 1];
}


int minimumEffortPath(vector<vector<int>>& height) {
    int m = height.size();
    int n = height[0].size();
    int l = 0;
    int h = 1e6;
    auto can = [&](int lim) {
        unordered_set<int> seen;
        queue<int> q;
        q.push(0);
        seen.insert(0);
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            int x = front / n;
            int y = front % n;
            if (x == m - 1 && y == n - 1) return true;
            for (auto d : dir) {
                int nx = d[0] + x;
                int ny = d[1] + y;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int code = nx * n + ny;
                int cdiff = abs(height[x][y] - height[nx][ny]);
                if (!seen.contains(code) && cdiff <= lim) {
                    seen.insert(code);
                    q.push(code);
                }
            }
        }
        return false;
    };
    while (l < h) {
        int mid = l + (h - l) / 2;
        if (can(mid)) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> h(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> h[i][j];
            }
        }
        cout << minimumEffortPath(h) << '\n';
    }
    return 0;
}