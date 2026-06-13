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

const int inf = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
	    int n, k;
	    cin >> n >> k;
	    vector<int> p(n);
	    int mn = inf;
	    int id = -1;
	    for (int i = 0; i < n; i++) {
	        cin >> p[i];
	        if (k < p[i]) continue;
	        int curr = (k % p[i] == 0 ? k / p[i] : inf);
	        if (curr < mn) {
	            id = i;
	            mn = curr;
	        }
	    }
	    cout << (id == -1 ? -1 : p[id]) << '\n';
    }
    return 0;
}