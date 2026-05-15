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


int findMin(vector<int>& nums) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    int k = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (mid + 1 < n && nums[mid] > nums[mid + 1]) {
            k = mid;
            break;
        }
        if (nums[l] <= nums[mid]) {
            l = mid + 1;
        } else if (nums[mid] <= nums[r]) {
            r = mid - 1;
        }
    }
    return nums[k + 1];
}

int findMin(vector<int>& nums) {
    int n = nums.size();
    int l = 0; 
    int r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[r]) {
            l = mid + 1;
        }
        else {
           r = mid; 
        }
    }
    return nums[l];
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
        cout << findMin(a) << '\n';
    }
    return 0;
}