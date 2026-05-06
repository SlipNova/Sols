#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
        return {};
    vector<string> ans;
    if (n == 1) {
        ans.push_back(to_string(nums[0]));
        return ans;
    }
    for (int i = 0; i < nums.size() - 1; i++) {
        string res = "";
        if (nums[i + 1] != nums[i] + 1) {
            res = to_string(nums[i]);
        } else {
            string start = to_string(nums[i]);
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            string end = to_string(nums[i]);
            res = start + "->" + end;
        }
        ans.push_back(res);
        if (i == n - 2) {
            ans.push_back(to_string(nums[i + 1]));
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<string> ans = summaryRanges(a);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}