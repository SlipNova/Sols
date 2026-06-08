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

vector<int> pivotArray1(vector<int>& a, int pivot) {
    vector<int> ls, gt;
    int c = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < pivot) {
            ls.push_back(a[i]);
        } else if (a[i] > pivot) {
            gt.push_back(a[i]);
        } else {
            c++;
        }
    }
    while (c--) {
        ls.push_back(pivot);
    }
    for (int i = 0; i < gt.size(); i++) {
        ls.push_back(gt[i]);
    }
    return ls;
}

vector<int> pivotArray(vector<int>& a, int pivot) {
    vector<int> ans;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < pivot)
            ans.push_back(a[i]);
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == pivot)
            ans.push_back(pivot);
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > pivot)
            ans.push_back(a[i]);
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, p;
        cin >> n >> p;
        vector<int> a(n), ans;
        for (int i = 0; i < n; i++) cin >> a[i];
        ans = pivotArray(a, p);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i != ans.size() ? ' ' : '\n');
        }
    }
    return 0;
}