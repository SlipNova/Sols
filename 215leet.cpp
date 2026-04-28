#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int findKthLargest1(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    return nums[k - 1];
}
int partition(vector<int>& a, int l, int r, int id) {
    int pivot = a[id];
    swap(a[r], a[id]);
    int i = l;
    for (int j = l; j < r; j++) {
        if (a[j] < pivot) {
            swap(a[j], a[i]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}

int quickSelect(vector<int>& a, int k) {
    int l = 0;
    int r = a.size() - 1;
    while (l <= r) {
        int id = l + rand() % (r - l + 1);
        int p = partition(a, l, r, id);
        if (p == k) {
            return a[p];
        } else if (p > k) {
            r = p - 1;
        } else {
            l = p + 1;
        }
    }
    return -1;
}

int findKthLargest2(vector<int>& nums, int k) {
    return quickSelect(nums, nums.size() - k);
}

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);
    }
    int c = 0;
    while (true) {
        int f = pq.top();
        pq.pop();
        c++;
        if (c == k) {
            return f;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt; cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << findKthLargest(a, k) << '\n';
    }
    return 0;
}