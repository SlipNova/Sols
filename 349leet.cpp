#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> a(1001, 0), ans;
    for (int i = 0; i < nums1.size(); i++) {
        a[nums1[i]] = 1;
    }
    for (int i = 0; i < nums2.size(); i++) {
        if (a[nums2[i]] == 0)
            continue;
        a[nums2[i]] += 1;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= 2)
            ans.push_back(i);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, n;
        cin >> m >> n;
        vector<int> a(m), b(n), ans;
        for (int i = 0; i < m; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        ans = intersection(a, b);
        for (int i = 0; i < a.size(); i++) {
            cout << ans[i] << (i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}