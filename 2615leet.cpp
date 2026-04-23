#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

vector<ll> distance(vector<int>& a) {
    int n = a.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]].push_back(i);
    }
    vector<ll> ans(n);
    for (auto& [val, freq] : mp) { 
        ll sum = 0;
        vector<ll> pref(freq.size());
        pref[0] = freq[0];
        for (int j = 1; j < freq.size(); j++) {
            pref[j] = pref[j - 1] + freq[j];
        }
        for (int j = 0; j < freq.size(); j++) {
            ll left, right;
            left = 0LL;
            right = left;
            int id = freq[j];
            if (j > 0) {
                left = 1LL * (j) * freq[j] - pref[j - 1];
            }
            if (j < freq.size() - 1) {
                right = pref[freq.size() - 1] - pref[j] - 1LL * (freq.size() - j - 1) * freq[j];
            }
            ans[id] = left + right;
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
        vector<ll> ans = distance(a);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i != a.size() - 1 ? ' ' : '\n');
        }
    }
    return 0;
}