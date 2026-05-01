#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}


int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();
    int f, sum;
    f = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
        f += i * nums[i];
        sum += nums[i];
    }
    int ans = f;
    for (int i = 1; i < n; i++) {
        f = f + sum - n * nums[n - i];
        ans = max(ans, f);
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
        cout << maxRotateFunction(a) << '\n';
    }
    return 0;
}