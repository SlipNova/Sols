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

string processStr(string s) {
    string result = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
            if (result.size() > 0)
                result.pop_back();
        } else if (s[i] == '#') {
            result += result;
        } else if (s[i] == '%') {
            reverse(result.begin(), result.end());
        } else {
            result += s[i];
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt; cin >> tt;
    while (tt--) {
        string str;
        cin >> str;
        cout << processStr(str) << '\n';
    }
    return 0;
}