#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    reverse(digits.begin(), digits.end());
    int carry = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            digits[i] += 1;
        }
        digits[i] += carry;
        if (digits[i] == 10) {
            carry = 1;
            digits[i] = 0;
        } else {
            carry = 0;
        }
    }
    if (carry == 1)
        digits.push_back(1);
    reverse(digits.begin(), digits.end());
    return digits;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> digits(n, -1), sol;
        for (int i = 0; i < n; i++) cin >> digits[i];
        sol = plusOne(digits);
        int a = sol.size();
        for (int i = 0; i < a; i++) {
            cout << sol[i] << (i == a - 1 ? '\n' : ' ');
        }
    }
    return 0;
}