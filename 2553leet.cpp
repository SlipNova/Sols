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

vector<int> separateDigits(vector<int>& nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        int val = nums[i];
        int s = ans.size();
        while (val > 0) {
            ans.push_back(val % 10);
            val /= 10;
        }
        reverse(ans.begin() + s, ans.end());
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
        vector<int> ans = separateDigits(a);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' '); 
        }
    }
    return 0;
}