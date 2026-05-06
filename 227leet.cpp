#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}


int calculate(string s) {
    vector<int> nums;
    char op = '+';
    int curr = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (i < s.size() && s[i] == ' ')
            continue;
        if (i < s.size() && isdigit(s[i])) {
            curr = curr * 10 + (s[i] - '0');
        }
        else {
            if (op == '+') {
                nums.push_back(curr);
            }
            else if (op == '-') {
                nums.push_back(-curr);
            }
            else if (op == '*') {
                nums.back() *= curr;
            }
            else if (op == '/') {
                nums.back() /= curr;
            }
            if (i < s.size()) op = s[i];
            curr = 0;
        }
    }
    int ans = 0;
    for (int x : nums) {
        ans += x;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        string str;
        cin >> str;
        cout << calculate(str) << '\n';
    }
    return 0;
}