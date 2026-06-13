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

string mapWordWeights(vector<string>& w, vector<int>& k) {
    int n = w.size();
    string ans = "";
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < w[i].size(); j++) {
            sum += k[w[i][j] - 'a'];
            sum %= 26;
        }
        sum = 25 - sum;
        ans += string(1, 'a' + sum);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> w(n);
        for (int i = 0; i < n; i++) cin >> w[i];
        vector<int> k(26);
        for (int i = 0; i < 26; i++) cin >> k[i];
        cout << mapWordWeights(w, k) << '\n';
    }
    return 0;
}