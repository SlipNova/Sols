#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int getMinDistance(vector<int> a, int target, int start) {
    int ans = INT_MAX;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == target) {
            ans = min(ans, abs(i - start));
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
        int n, target , start;
        cin >> n >> target >> start;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << getMinDistance(a, target, start) << '\n';
    }
    return 0;
}