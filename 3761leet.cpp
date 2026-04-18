#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int reverse(int n) {
    if (n == 0)
        return 0;
    int k = n;
    int sz = 1;
    while (k % 10 == 0) {
        k /= 10;
    }
    int l = k;
    int m = 0;
    while (l > 0) {
        l /= 10;
        sz *= 10;
    }
    sz /= 10;
    while (sz > 0) {
        m += k % 10 * sz;
        sz /= 10;
        k /= 10;
    }
    return m;
}

int minMirrorPairDistance(vector<int>& nums) {
    int n = nums.size();
    int sol = INT_MAX;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int m = reverse(nums[i]);
        if (mp.contains(nums[i])) {
            sol = min(abs(mp[nums[i]] - i), sol);
        }
        mp[m] = i;
    }
    return (sol == INT_MAX ? -1 : sol);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n, -1);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << minMirrorPairDistance(a) << '\n';
    }
    return 0;
}