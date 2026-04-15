#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int closestTarget(vector<string>& words, string target, int sid) {
    if (words[sid] == target) return 0;
    int n = words.size();
    int l, r, k;
    k = 1;
    r = sid + 1;
    l = sid - 1;
    while (k < n) {
        if (r == n) r = 0;
        if (l == -1) l = n - 1;
        if (words[l] == target || words[r] == target) return k;
        l -= 1;
        r += 1;
        k++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, sid;
        string target;
        cin >> n >> target >> sid;
        vector<string> words(n, "");
        for (int i = 0; i < n; i++) cin >> words[i];
        cout << closestTarget(words, target, sid) << '\n';
    }
    return 0;
}