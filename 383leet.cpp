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

bool canConstruct(string ransomNote, string magazine) {
    if (magazine.size() < ransomNote.size())
        return false;
    vector<int> a(26, 0), b(26, 0);
    for (int i = 0; i < magazine.size(); i++) {
        a[magazine[i] - 'a']++;
    }
    for (int i = 0; i < ransomNote.size(); i++) {
        b[ransomNote[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (b[i] > a[i])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        string ransomNote, magazine;
        cin >> ransomNote >> magazine;
        cout << (canConstruct(ransomNote, magazine) ? "Yes" : "No") << '\n';
    }
    return 0;
}