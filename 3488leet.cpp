#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int bsn(vector<int>& a, int target, int n) {
    int m = a.size();
    int l = 0;
    int r = m - 1;
    int pos = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == target) {
            pos = mid;
            break;
        }
        else if (a[mid] > target) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    int prev = a[(pos - 1 + m) % m];
    int nex = a[(pos + 1 + m) % m];
    int d1 = abs(target - prev);
    int d2 = abs(target - nex);
    d1 = min(d1, n - d1);
    d2 = min(d2, n - d2);
    return min(d1, d2);
}

vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();
    int q = queries.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[nums[i]].push_back(i);
    }
    vector<int> sol;
    for (int i = 0; i < q; i++) {
        vector<int>& a = mp[nums[queries[i]]];
        if (a.size() == 1) {
            sol.push_back(-1);
            continue;
        }
        sol.push_back(bsn(a, queries[i], n));
    }
    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt; cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        vector<int> nums(a, 0), queries(b, 0);
        for (int i = 0; i < a; i++) cin >> nums[i];
        for (int i = 0; i < b; i++) cin >> queries[i];
        vector<int> sol = solveQueries(nums, queries);
        int k = sol.size();
        for (int i = 0; i < k; i++) {
            cout << sol[i] << ((i == k - 1) ? '\n' : ' ');
        }
    }
    return 0;
}