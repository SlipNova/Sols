#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}


void solve(int bound) {
    unordered_map<ll, vector<pair<int, int>>> mp;
    for (int a = 1; a < bound; a++) {
        ll a3 = 1LL * a * a * a;
        for (int b = a; b < bound; b++) {
            ll s = a3 + 1LL * b * b * b;
            mp[s].push_back({a, b});
        }
    }
    ll count = 0;
    for (auto &entry : mp) {
        auto &vec = entry.second;
        int k = vec.size();
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                auto [a, b] = vec[i];
                auto [c, d] = vec[j];
                cout << a << ' ' << b << ' ' << c << ' ' << d << " : " << entry.first << '\n';
            }
        }
        count += 1LL * k * (k - 1) / 2;
    }
    cout << "Solution count = " << count << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int bound;
    cin >> bound;
    solve(bound);
    return 0;
}