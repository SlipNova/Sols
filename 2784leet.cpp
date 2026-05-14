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

bool isGood(vector<int>& a) {
    int n = a.size();
    if (n == 1)
        return false;
    vector<int> freq(n, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] > n - 1 || a[i] <= 0)
            return false;
        freq[a[i]]++;
    }
    for (int i = 1; i < n - 1; i++) {
        if (freq[i] != 1)
            return false;
    }
    return (freq[n - 1] == 2);
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
        cout << (isGood(a) ? "True" : "False") << '\n';
    }
    return 0;
}