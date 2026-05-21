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

vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
    int m = chunks.size();
    int n = queries.size();
    unordered_map<string, int> freq;
    string str = "";
    for (int i = 0; i < m; i++) {
        str += chunks[i];
    }
    auto ok = [&](char c) {
        if (c >= 'a' && c <= 'z')
            return true;
        return false;
    };
    int len = str.size();
    string curr = "";
    for (int i = 0; i < len; i++) {
        if (ok(str[i])) {
            curr += str[i];
        } else if (str[i] == '-' && i + 1 < len && i > 0 && ok(str[i + 1]) &&
                   ok(str[i - 1])) {
            curr += str[i];
        } else {
            if (curr != "") {
                freq[curr]++;
                curr = "";
            }
        }
    }
    if (curr != "")
        freq[curr]++;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (freq.contains(queries[i])) {
            ans[i] = freq[queries[i]];
        } else {
            ans[i] = 0;
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
        int cl, ql;
        cin >> cl >> ql;
        vector<string> c(cl), q(ql);
        for (int i = 0; i < cl; i++) cin >> c[i];
        for (int i = 0; i < ql; i++) cin >> q[i];
        vector<int> ans = countWordOccurrences(c, q);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}