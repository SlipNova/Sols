#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

void merge(vector<int>& a, int m, vector<int>& b, int n) {
    int f, s;
    f = m - 1;
    s = n - 1;
    int l = m + n - 1;
    while (l >= 0 && f >= 0 && s >= 0) {
        if (a[f] > b[s]) {
            a[l] = a[f];
            f--;
        } else {
            a[l] = b[s];
            s--;
        }
        l--;
    }
    while (f >= 0) {
        a[l] = a[f];
        l--;
        f--;
    }
    while (s >= 0) {
        a[l] = b[s];
        l--;
        s--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, n;
        cin >> m >> n;
        vector<int> a(m + n, 0), b(n, 0);
        for (int i = 0; i < m; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        merge(a, m, b, n);
        for (int i = 0; i < m + n; i++) {
            cout << a[i] << (i != m + n - 1 ? ' ' : '\n');
        }
    }
    return 0;
}