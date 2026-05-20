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

string getHint(string secret, string guess) {
    int n = guess.size();
    int bulls = 0;
    vector<int> s(10, 0);
    vector<int> g(10, 0);
    for (int i = 0; i < n; i++) {
        if (secret[i] == guess[i]) {
            bulls++;
            continue;
        }
        s[secret[i] - '0']++;
        g[guess[i] - '0']++;
    }
    int cows = 0;
    for (int i = 0; i < 10; i++) {
        cows += min(g[i], s[i]);
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        string secret, guess;
        cin >> secret >> guess;
        cout << getHint(secret, guess) << '\n';
    }
    return 0;
}