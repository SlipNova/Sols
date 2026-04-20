#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int maxDistance1(vector<int>& a) {
    int n = a.size();
    int dist = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] != a[j]) {
                dist = max(dist, abs(i - j));
            }
        }
    }
    return dist;
}

int maxDistance(vector<int>& a) {
    int n = a.size();
    int lc = a[0];
    int rc = a[n - 1];
    int dist = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] != lc) {
            dist = max(dist, i);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != rc) {
            dist = max(dist, n - 1 - i);
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << maxDistance(a) << '\n';
    }
    return 0;
}