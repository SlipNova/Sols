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

int mystoi(string k) {
    if (k == "") return 0;
    return (stoi(k));
}


bool ok(int n) {
    long long N = 1LL * n * n;
    int len = (to_string(n).size());
    string str = to_string(N);
    string a, b;
    a = "";
    b = "";
    for (int i = str.size() - 1; i >= 0; i--) {
        if (i >= str.size() - len) {
            a = str[i] + a;
        }
        else {
            b = str[i] + b;
        }
    }
    int n2 = mystoi(a);
    int n1 = mystoi(b);
    if (n2 > 0 && n == n1 + n2) {
        return true;
    }

    return false; 
}



void kaprekarNumbers(int p, int q) {
    bool first = true;
    for (int i = p; i <= q; i++) {
        if (ok(i)) {
            if (!first) cout << ' ';
            cout << i;
            first = false;
        }
    }
    if (first) cout << "INVALID RANGE";
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p, q;
    cin >> p >> q;
    kaprekarNumbers(p, q);
    return 0;
}