#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

vector<int> change = {2, 5, 6, 9};
vector<int> invalid = {3, 4, 7};
vector<int> same = {0, 1, 8};

bool isGood(int n) {
    bool ok = false;
    while (n > 0) {
        int digit = n % 10;
        if (binary_search(invalid.begin(), invalid.end(), digit)) {
            return false;
        }
        if (binary_search(change.begin(), change.end(), digit)) {
            ok = true;
        }
        n /= 10;
    }
    return ok;
}

int rotatedDigits1(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (isGood(i)) ans++;
    }
    return ans;
}

int bpow(int base, int exp) {
    int res = 1;
    while (exp != 0) {
        if (exp & 1) {
            res *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return res;
}

int rotatedDigits(int n) {
    string s = to_string(n);
    int len = s.size();
    int ans = 0;
    vector<int> valid = {0,1,2,5,6,8,9};
    auto changed = [&] (int d) {
        return binary_search(change.begin(), change.end(), d);
    };
    for (int i = 1; i < len; i++) {
        ans += 6 * bpow(7, i - 1) - 2 * bpow(3, i - 1);
    }
    bool used = false;
    for (int i = 0; i < len; i++) {
        int curr = s[i] - '0';
        int left = len - i - 1;
        for (auto d : valid) {
            if (i == 0 && d == 0) continue;
            if (d >= curr) break;
            bool cn = used || changed(d);
            if (cn) {
                ans += bpow(7, left);
            }
            else {
                ans += bpow(7, left) - bpow(3, left);
            }
        }
        if (!binary_search(valid.begin(), valid.end(), curr)) {
            return ans;
        }
        if (changed(curr)) {
            used = true;
        }
    }
    if (used) ans++;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        cout << rotatedDigits(n) << '\n';
    }
    return 0;
}