#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

string addBinary(string a, string b) {
    if (a.length() < b.length())
        return addBinary(b, a);
    int aa = a.length();
    int bb = b.length();
    b = string(aa - bb, '0') + b;
    bool carry = false;
    string res = "";
    for (int i = aa - 1; i >= 0; i--) {
        if (a[i] == b[i] && a[i] == '1') {
            if (carry) {
                res += "1";
            } else {
                res += "0";
            }
            carry = true;
        } else if (a[i] == b[i] && a[i] == '0') {
            if (carry) {
                res += "1";
            } else {
                res += "0";
            }
            carry = false;
        } else if (carry) {
            res += "0";
            carry = true;
        } else {
            res += "1";
            carry = false;
        }
    }
    if (carry) {
        res += "1";
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        string a, b;
        cin >> a >> b;
        cout << addBinary(a, b) << '\n';
    }
    return 0;
}