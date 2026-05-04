#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int lengthOfLastWord(string s) {
    int end = s.length() - 1;
    int ans = 0;
    while (s[end] == ' ') {
        end--;
    }
    while (end >= 0 && s[end] != ' ') {
        end--;
        ans++;
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
        cout << lengthOfLastWord(str) << '\n';
    }
    return 0;
}