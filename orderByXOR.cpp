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




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> need(30, -1);
        auto add = [&] (int x, int y) {
            int k = -1;
            for (int i = 29; i >= 0; i--) {
                if ((x & (1 << i)) != (y & (1 << i))) {
                    k = i;
                    break;
                }
            }
            int xd = ((x & (1 << k)) ? 1 : 0);
            if (need[k] != -1 && need[k] != xd) return false;
            need[k] = xd;
            return true;
        };
        int x = -1;
        if (add(a, b) && add (b, c)) {
            x = 0;
            for (int i = 0; i < 30; i++) {
                if (need[i] == 1) {
                    x |= (1 << i);
                }
            }
            cout << x << '\n';
        }
        else {
            cout << x << '\n';
        }
    }
    return 0;
}