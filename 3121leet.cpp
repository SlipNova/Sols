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


int numberOfSpecialChars(string word) {
    int n = word.size();
    int ans = 0;
    vector<pair<int, int>> f(26, pair<int, int>(-1, -1));
    for (int i = 0; i < n; i++) {
        if (islower(word[i])) {
            f[word[i] - 'a'].first = i;
        } else {
            int t = word[i] - 'A';
            if (f[t].second == -1)
                f[t].second = i;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (f[i].first == -1 || f[i].second == -1)
            continue;
        if (f[i].first < f[i].second)
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
        cout << numberOfSpecialChars(str) << '\n';
    }
    return 0;
}