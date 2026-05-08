#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}


int solve(vector<int>& a, vector<int>& ans, vector<int>& mx, int r, int& rmax, int& rmin) {
    int id = mx[r];
    int curr = (a[id] > rmin ? rmax : a[id]);
    for (int i = id; i <= r; i++) {
        ans[i] = curr;
        rmin = min(rmin, a[i]);
    }
    rmax = curr;
    return id - 1;
}


vector<int> maxValue1(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n), mx(n, -1);
    mx[0] = 0;
    for (int i = 1; i < n; i++) {
        mx[i] = (a[i] > a[mx[i - 1]] ? i : mx[i - 1]);
    }
    int r = n - 1;
    int rmax = INT_MIN;
    int rmin = INT_MAX;
    while (r >= 0) {
        r = solve(a, ans, mx, r, rmax, rmin);
    }
    return ans;
}

vector<int> maxValue(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n), mx(n), mn(n);
    mx[0] = a[0];
    mn[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++) {
        mx[i] = max(a[i], mx[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        mn[i] = min(a[i], mn[i + 1]);
    }
    ans[n - 1] = mx[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (mx[i] <= mn[i + 1]) {
            ans[i] = mx[i];
        }
        else {
            ans[i] = ans[i + 1];
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
        vector<int> a(n), ans;
        for (int i = 0; i < n; i++) cin >> a[i];
        ans = maxValue(a);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i != ans.size() - 1 ? ' ' : '\n');
        }
    }
    return 0;
}