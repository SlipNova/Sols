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


vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<int> c(n);
    vector<int> freq(51, 0);
    int common = 0;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
        if (freq[a[i]] == 2) {
            common++;
        }
        freq[b[i]]++;
        if (freq[b[i]] == 2) {
            common++;
        }
        c[i] = common;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<int> c = findThePrefixCommonArray(a, b);
        for (int i = 0; i < n; i++) {
            cout << c[i] << (i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}