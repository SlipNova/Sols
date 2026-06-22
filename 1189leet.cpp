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

int maxNumberOfBalloons(string text) {
    vector<int> b(5, 0); // balon
    for (int i = 0; i < text.size(); i++) {
        char k = text[i];
        if (k == 'b') {
            b[0]++;
        } else if (k == 'a') {
            b[1]++;
        } else if (k == 'l') {
            b[2]++;
        } else if (k == 'o') {
            b[3]++;
        } else if (k == 'n') {
            b[4]++;
        }
    }
    b[2] /= 2;
    b[3] /= 2;
    int mn = INT_MAX;
    for (int i = 0; i < b.size(); i++) {
        mn = min(mn, b[i]);
    }
    return mn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        string text;
        cin >> text;
        cout << maxNumberOfBalloons(text) << '\n';
    }
    return 0;
}