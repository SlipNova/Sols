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

vector<int> concatWithReverse(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans = nums;
    for (int i = n - 1; i >= 0; i--) {
        ans.push_back(nums[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), sol;
        for (int i = 0; i < n; i++) cin >> a[i];
        sol = concatWithReverse(a);
        for (int i = 0; i < sol.size(); i++) {
            cout << sol[i] << (i == sol.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}