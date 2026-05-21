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



int longestCommonPrefix1(vector<int>& a, vector<int>& b) {
    int m = a.size();
    int n = b.size();
    unordered_map<string, bool> sa;
    for (int j = 0; j < m; j++) {
        string str = to_string(a[j]);
        int l = str.length();
        string k = "";
        for (int i = 0; i < l; i++) {
            k += str[i];
            sa[k] = true;
        }
    }
    int ans = 0;
    for (int j = 0; j < n; j++) {
        string str = to_string(b[j]);
        int l = str.length();
        string k = "";
        for (int i = 0; i < l; i++) {
            k += str[i];
            if (sa[k]) {
                ans = max(ans, i + 1);
            }
        }
    }
    return ans;
}

int longestCommonPrefix(vector<int>& a, vector<int>& b) {
    int ans = 0;
    unordered_set<int> s;
    s.reserve(a.size() * 10);
    for (auto num : a) {
        while (num > 0) {
            s.insert(num);
            num /= 10;
        }
    }
    for (auto num : b) {
        int len = to_string(num).size();
        while (num > 0) {
            if (s.contains(num)) {
                ans = max(ans, len);
                break;
            }
            num /= 10; 
            len--;
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, n;
        cin >> m >> n;
        vector<int> a(m), b(n);
        for (int i = 0; i < m; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        cout << longestCommonPrefix(a, b) << '\n';
    }
    return 0;
}