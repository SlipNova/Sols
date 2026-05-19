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

bool canReach(vector<int>& a, int start) {
    int n = a.size();
    vector<int> can(n, false);
    can[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        int f, b;
        f = -1;
        b = -1;
        if (curr >= 0 && curr < n) {
            if (curr + a[curr] < n) {
                f = curr + a[curr];
            }
            if (curr - a[curr] >= 0) {
                b = curr - a[curr];
            }
        }
        if (f != -1 && !can[f]) {
            can[f] = true;
            q.push(f);
        }
        if (b != -1 && !can[b]) {
            can[b] = true;
            q.push(b);
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && can[i]) {
            return true;
        }
    }
    return false;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, start;
        cin >> n >> start;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << (canReach(a, start) ? "True" : "False") << '\n';
    }
    return 0;
}