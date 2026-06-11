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

template <typename T, class F>
struct SparseTable {
    int n, LOG;
    vector<vector<T>> st;
    F op;

    SparseTable(const vector<T>& a, F f) : op(f) {
        n = a.size();
        LOG = __lg(n) + 1;
        st.assign(LOG, vector<T>(n));
        st[0] = a;
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = op(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T query(int l, int r) const {
        int j = __lg(r - l + 1);
        return op(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

ll maxTotalValue(vector<int>& a, int k) {
    int n = a.size();
    auto mx = [](int a, int b) {
        return max(a, b);
    };
    auto mn = [](int a, int b) {
        return min(a, b);
    };
    SparseTable<int, decltype(mx)> stMax(a, mx);
    SparseTable<int, decltype(mn)> stMin(a, mn);
    priority_queue<tuple<int, int, int>> pq;
    for (int l = 0; l < n; l++) {
        pq.push({stMax.query(l, n - 1) - stMin.query(l, n - 1), l, n - 1});
    }
    ll ans = 0;
    while (k--) {
        auto [val, l, r] = pq.top();
        pq.pop();
        ans += 1ll * val;
        if (r - 1 >= l) {
            pq.push({stMax.query(l, r - 1) - stMin.query(l, r - 1), l, r - 1});
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << maxTotalValue(a, k) << '\n';
    }
    return 0;
}