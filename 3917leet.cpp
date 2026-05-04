#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

vector<int> countOppositeParity(vector<int>& nums) {
    int n = nums.size();
    int odd = 0;
    int even = 0;
    vector<int> ans(n);
    for (int i = n - 1; i > - 1; i--) {
        if (nums[i] %  2) { // odd
            ans[i] = even;
            odd++;
        }
        else {
            ans[i] = odd;
            even++;
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
        vector<int> ans = countOppositeParity(a);
        for (int i = 0; i < n; i++) {
            cout << a[i] << (i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}