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

int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int q = queries.size();
    for (int i = 0; i < q; i++) {
        int idx = queries[i][0];
        int ri = queries[i][1];
        int ki = queries[i][2];
        int vi = queries[i][3];
        while (idx <= ri) {
            nums[idx] = (1LL * nums[idx] * vi) % MOD;
            idx += ki;
        }
    }
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        ans ^= nums[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> nums(n);
        vector<vector<int>> queries(q);
        for (int i = 0; i < n; i++) cin >> nums[i];
        for (int i = 0; i < q; i++) {
            cin >> queries[i][0] >> queries[i][1] >> queries[i][2] >> queries[i][3];
        }
        cout << xorAfterQueries(nums, queries) << '\n';
    }
    return 0;
}