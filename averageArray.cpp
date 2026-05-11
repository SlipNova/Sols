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

void solve(int n, int x) {
    int end = n - 1;
    int k = 1;
    while (end >= 0) {
        cout << x - k << ' ' << x + k;
        k++;
        end -= 2;
        cout << (end < 0 ? '\n' : ' ');
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        int end, k;
        end = n - 1;
        k = 1;
        if (n % 2 == 0) {
            solve(n, x);
        }
        else {
            cout << x << ' ';
            solve(n - 1, x);
        }
    }
    return 0;
}