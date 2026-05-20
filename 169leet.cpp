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

int majorityElement(vector<int>& a) {
    int n = a.size();
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
        if (freq[a[i]] > n / 2) return a[i];
    }
    return -1;
}

int majorityElement(vector<int>& a) {
    int n = a.size();
    int candidate = a[0];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == candidate) {
            count++;
        }
        else {
            count--;
        }
        if (count == 0) {
            candidate = a[i];
            count++;
        }
    }
    return candidate;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << majorityElement(a) << '\n';
    }
    return 0;
}