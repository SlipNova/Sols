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

// too slow O(n * limit)
// WLOG assume ai <= aj then for x in [ai + 1, aj + limit] we need 1 modification for x, 
// ai + aj == x we need 0
// else we need 2 modifications for x
int minMoves(vector<int>& a, int limit) {
    int n = a.size();
    vector<int> A(2 * limit + 2);
    auto need = [&] (int x, int ai, int aj) {
        ai = min(ai, aj);
        aj = max(ai, aj);
        if (x == ai + aj) {
            return 0;
        }
        else if (x <= aj + limit && x >= ai + 1) {
            return 1;
        }
        return 2;
    };
    for (int i = 2; i < A.size(); i++) {
        int sum = 0;
        for (int j = 0; j < n / 2; j++) {
            int ai = a[j];
            int aj = a[n - j - 1];
            sum += need(i, ai, aj);
        }
        A[i] = sum;
    }
    int ans = INT_MAX;
    for (int i = 2; i < A.size(); i++) {
        ans = min(ans, A[i]);
    }
    return ans;
}

int minMoves(vector<int>& a, int limit) {
    int n = a.size();
    vector<int> diff(2 * limit + 2, 0);
    for (int i = 0; i < n / 2; i++) {
        int ai = a[i];
        int aj = a[n - i - 1];
        int low = min(ai, aj) + 1;
        int high = max(ai, aj) + limit;
        int same = ai + aj;
        diff[2] += 2;
        diff[2 * limit + 1] -= 2;
        diff[low] -= 1;
        diff[high + 1] += 1;
        diff[same] -= 1;
        diff[same + 1] += 1; // same is always in the range [low, high]
    }
    int ans = INT_MAX;
    int curr = 0;
    for (int i = 2; i < 2 * limit + 1; i++) {
        curr += diff[i];
        ans = min(ans, curr);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, limit;
        cin >> n >> limit;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << minMoves(a, limit) << '\n';
    }
    return 0;
}