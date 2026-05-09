#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}


bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[l] == nums[r] && nums[r] == nums[mid]) {
            while (l < r && nums[l] == nums[l + 1])
                l++;
            while (l < r && nums[r] == nums[r - 1])
                r--;
            l++;
            r--;
        } else if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (nums[mid] < target && nums[r] >= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, target; 
        cin >> n >> target;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << (search(a, target) ? "True" : "False") << '\n';
    }
    return 0;
}