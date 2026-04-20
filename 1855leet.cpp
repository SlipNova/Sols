#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int bs(vector<int>& a, int target,
       int start) { // find the max index where a[id] >= target
    int n = a.size();
    int l, r;
    l = start;
    r = n - 1;
    int id = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= target) {
            id = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return id;
}

int maxDistance1(vector<int>& n1, vector<int>& n2) {
    int a = n1.size();
    int b = n2.size();
    int mx = 0;
    for (int i = 0; i < a; i++) {
        int id = bs(n2, n1[i], i);
        mx = max(mx, id - i);
    }
    return mx;
}

int maxDistance(vector<int>& n1, vector<int>& n2) {
    int a = n1.size();
    int b = n2.size();
    int f, s, dist;
    f = 0;
    s = 0;
    dist = 0;
    while (f < a && s < b) {
        if (n1[f] <= n2[s]) {
            dist = max(dist, s - f);
            s++;
        }
        else {
            f++;
        }
    }
    return dist;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        vector<int> nums1(a, -1), nums2(b, -1);
        for (int i = 0; i < a; i++) cin >> nums1[i];
        for (int i = 0; i < b; i++) cin >> nums2[i];
        cout << maxDistance(nums1, nums2) << '\n';
    }
    return 0;
}