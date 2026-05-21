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

long long minArraySum(vector<int>& nums) {
    int n = nums.size();
    ll ans = 0;
    sort(nums.begin(), nums.end());
    vector<int> f(1e5 + 1, 0);
    for (int i = 0; i < n; i++) {
        f[nums[i]]++;
    }
    if (f[1] >= 1) {
        return nums.size();
    }
    for (int i = 0; i < n; i++) {
        int curr = nums[i];
        if (f[curr] == 0)
            continue;
        int mx = 1e5 / curr;
        for (int j = 2; j <= mx; j++) {
            int id = curr * j;
            if (f[id] >= 1) {
                f[curr] += f[id];
                f[id] = 0;
            }
        }
    }
    for (ll i = 0; i < f.size(); i++) {
        if (f[i] == 0)
            continue;
        ans += (ll)(f[i] * i);
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << minArraySum(a) << '\n';
    }
    return 0;
}