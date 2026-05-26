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
    vector<int> freq(26, 0);
    int count = 0;
    for (int i = 0; i < word.size(); i++) {
        int p = word[i] - 'a';
        if (p >= 0 && p < 26)
            freq[p]++;
    }
    for (int i = 0; i < word.size(); i++) {
        if (islower(word[i]))
            continue;
        if (freq[tolower(word[i]) - 'a'] > 0) {
            count++;
            freq[tolower(word[i]) - 'a'] = 0;
        }
    }
    return count;
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