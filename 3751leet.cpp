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


int totalWaviness(int a, int b) {
    int ans = 0;
    vector<int> d(10);
    int sz;
    for (int i = a; i <= b; i++) {
        int num = i;
        sz = 0;
        while (num > 0) {
            d[sz] = num % 10;
            num /= 10;
            sz++;
        }
        for (int j = 1; j < sz - 1; j++) {
            if (d[j - 1] < d[j] && d[j] > d[j + 1])
                ans++;
            if (d[j - 1] > d[j] && d[j] < d[j + 1])
                ans++;
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
        int a, b;
        cin >> a >> b;
        cout << totalWaviness(a, b) << '\n';
    }
    return 0;
}