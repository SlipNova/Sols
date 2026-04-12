#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int minimumDistance(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[nums[i]].push_back(i);
    }
    int ans = INT_MAX;
    for (const auto& [key, a] : mp) {
        int sz = a.size();
        if (sz >= 3) {
            for (int i = 0; i < sz - 2; i++) {
                ans = min(ans, 2 * (a[i + 2] - a[i]));
            }
        }
    }
    /*
    for (auto it: mp) {
        cout << it.first << ':';
        vector<int> b = it.second;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << ' ';
        }
        cout << '\n';
    }
    */
    return ans == INT_MAX ? -1 : ans;
}

int minimumDistances(vector<int> nums) {
    int n = nums.size();
    vector<int> id(n);
    for (int i = 0; i < n; i++) id[i] = i;
    auto comp = [&] (int a, int b) {
        if (nums[a] != nums[b]) return nums[a] < nums[b];
        return a < b;
    };
    sort(id.begin(), id.end(), comp);
    int ans = INT_MAX;
    for (int i = 0; i + 2 < n; i++) {
        if (nums[id[i]] == nums[id[i + 2]]) {
            ans = min(ans, id[i + 2] - id[i]);
        }
    }
    return ans == INT_MAX ? -1 : 2 * ans;
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
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << minimumDistance(nums) << '\n';
    }
    return 0;
}