#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

const int inf = INT_MAX;

int minimumDistance(vector<int>& a) {
    int mx = inf;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] != a[j]) continue;
            for (int k = j + 1; k < n; k++) {
                if (a[j] == a[k]) {
                    mx = min(mx, 2 * (k - i));
                }
            }
        }
    }
    return mx == INT_MAX ? -1 : mx;
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
        cout << minimumDistance(a) << '\n';
    }
    return 0;
}