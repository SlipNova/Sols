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

deque<int> solve(int n) {
    deque<int> ans = {3, 1, 2};
    for (int x = 4; x <= n; x++) {
        if (ans[0] == x - 1) {
            ans.push_back(x);
        } else {
            ans.push_front(x);
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
        deque<int> ans = solve(n);
        for (auto it = ans.begin(); it != ans.end(); it++) {
            cout << *it << (it == ans.end() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}