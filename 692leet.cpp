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


vector<string> topKFrequent(vector<string>& a, int k) {
    int n = a.size();
    unordered_map<string, int> freq;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }
    auto cmp = [] (pair<string, int>& a, pair<string, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
    for (auto& [key, value] : freq) {
        pq.push({key, value});
    }
    vector<string> ans;
    while (k--) {
        ans.push_back(pq.top().first);
        pq.pop();
    }
    return ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<string> ans = topKFrequent(a, k);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}