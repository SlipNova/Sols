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

// mx = max(f)
// c = |{i : f(i) = mx}|
// n = interval length
// ans = mx(n + 1) + c - n - 1
int leastInterval(vector<char>& a, int n) {
    int m = a.size();
    vector<int> freq(26, 0);
    for (int i = 0; i < m; i++) {
        freq[a[i] - 'A']++;
    }
    int mx = -1;
    for (int i = 0; i < 26; i++) {
        mx = max(mx, freq[i]);
    }
    int c = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == mx) c++;
    }
    return max(m, mx * (n + 1) + c - n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, n;
        cin >> m >> n;
        vector<char> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        cout << leastInterval(a, n) << '\n';
    }
    return 0;
}