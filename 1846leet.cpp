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

int maximumElementAfterDecrementingAndRearranging1(vector<int>& arr) {
    int n = arr.size();
    if (n == 1)
        return 1;
    sort(arr.begin(), arr.end());
    arr[0] = 1;
    for (int i = 1; i < n - 1; i++) {
        if (abs(arr[i] - arr[i - 1]) > 1) {
            arr[i] = arr[i - 1] + 1;
        }
    }
    int ans = arr[n - 1];
    if (ans != arr[n - 2]) {
        ans = arr[n - 2] + 1;
    }
    return ans;
}

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    int n = arr.size();
    vector<int> c(n + 1, 0);
    for (int i = 0; i < n; i++) {
        c[min(arr[i], n)]++;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = min(ans + c[i], i);
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
        cout << maximumElementAfterDecrementingAndRearranging(a) << '\n';
    }
    return 0;
}