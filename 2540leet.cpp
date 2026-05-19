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

int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int f, s;
    f = 0;
    s = 0;
    while (f < nums1.size() && s < nums2.size()) {
        if (nums1[f] == nums2[s]) {
            return nums1[f];
        } else if (nums1[f] < nums2[s]) {
            f++;
        } else {
            s++;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        vector<int> nums1(a), nums2(b);
        for (int i = 0; i < a; i++) cin >> nums1[i];
        for (int i = 0; i < b; i++) cin >> nums2[i];
        cout << getCommon(nums1, nums2) << '\n';
    }
    return 0;
}