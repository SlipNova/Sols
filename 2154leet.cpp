#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int findFinalValues(vector<int>& nums, int original) {
    int n = nums.size();
    unordered_map<int, bool> mp;
    for (int i = 0; i < n; i++) {
        mp[nums[i]] = true;
    }
    while (mp.contains(original)) {
        original *= 2;
    }
    return original;
}

int findFinalValue(vector<int>& nums, int original) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (nums[i] == original) {
            original *= 2;
        }
    }
    return original;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, original;
        cin >> n >> original;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << findFinalValue(a, original) << '\n';
    }
    return 0;
}