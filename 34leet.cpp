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

int first_pos(vector<int>& a, int x) {
    int n = a.size();
    int l = 0;
    int r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

vector<int> searchRange1(vector<int>& nums, int target) {
    int first = first_pos(nums, target);
    int second = first_pos(nums, target + 1) - 1;
    if (first <= second) {
        return {first, second};
    }
    return {-1, -1};
}

vector<int> searchRange(vector<int>& a, int x) {
    int first = lower_bound(a.begin(), a.end(), x) - a.begin();
    int second = lower_bound(a.begin(), a.end(), x + 1) - a.begin() - 1;
    if (first <= second) {
        return {first, second};
    }
    return {-1, -1};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> ans = searchRange(a, x);
        cout << ans[0] << ' ' << ans[1] << '\n';
    }
    return 0;
}