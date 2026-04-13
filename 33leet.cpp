#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int bs(vector<int>& a, int l, int h, int target) {
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (a[mid] == target) {
            return mid;
        }
        else if (a[mid] > target) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;
}

int search(vector<int>& a, int target) {
    int n = a.size();
    int l, h;
    l = 0; h = n - 1;
    int k = -1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (mid + 1 < n && a[mid] > a[mid + 1]) {
            k = mid;
            break;
        }
        if (a[mid] < a[0]) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
        
    }
    if (k == -1) return bs(a, 0, n - 1, target);
    if (a[k] == target) {
        return k;
    }
    else if (a[k] > target && a[0] <= target) {
        l = 0;
        h = k - 1;
    }
    else {
        h = n - 1;
        l = k + 1;
    }
    return bs(a, l, h, target);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, target;
        cin >> n >> target;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << search(a, target) << '\n';
    }
    return 0;
}