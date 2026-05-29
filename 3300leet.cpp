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

int minElement(vector<int>& nums) {
    auto sumD = [](int a) {
        int k = 0;
        while (a > 0) {
            k += a % 10;
            a /= 10;
        }
        return k;
    };
    int mn = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        mn = min(mn, sumD(nums[i]));
    }
    return mn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        cout << minElement(nums) << '\n';
    }
    return 0;
}