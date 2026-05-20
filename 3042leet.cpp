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

int countPrefixSuffixPairs1(vector<string>& words) {
    auto good = [](const string& str, const string& word) {
        int n = word.size();
        int len = str.size();
        if (len > n)
            return false;
        bool isPrefix = word.compare(0, len, str) == 0;
        bool isSuffix = word.compare(n - len, len, str) == 0;
        return isPrefix && isSuffix;
    };
    int ans = 0;
    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            if (good(words[i], words[j]))
                ans++;
        }
    }
    return ans;
}

int countPrefixSuffixPairs(vector<string>& words) {
    unordered_map<string, int> seen;
    int ans = 0;
    for (int i = 0; i < words.size(); i++) {
        int n = words[i].size();
        for (int j = 1; j <= n; j++) {
            string pref = words[i].substr(0, j);
            if (pref == words[i].substr(n - j, j)) {
                ans += seen[pref];
            }
        }
        seen[words[i]]++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt; cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << countPrefixSuffixPairs(a) << '\n';
    }
    return 0;
}