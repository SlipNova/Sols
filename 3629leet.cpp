#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

static const int mxx = 1000000;

vector<bool> generate(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

const vector<bool> prime = generate(1000001);

int minJumps1(vector<int>& a) {
    int n = a.size();
    queue<int> q;
    vector<int> d(n, -1);
    unordered_set<int> done;
    unordered_map<int, vector<int>> jumps;
    for (int i = 0; i < n; i++) {
        int val = a[i];
        for (int p = 2; p * p <= val; p++) {
            if (prime[p] && val % p == 0) jumps[p].push_back(i);
            while (val % p == 0) val /= p;
        }
        if (val > 1 && prime[val]) jumps[val].push_back(i); 
    }
    d[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int id = q.front();
        q.pop();
        if (id - 1 >= 0 && d[id - 1] == -1) {
            d[id - 1] = d[id] + 1;
            q.push(id - 1);
        }
        if (id + 1 < n && d[id + 1] == -1) {
            d[id +  1] = d[id] + 1;
            q.push(id + 1);
        }
        if (prime[a[id]] && !done.count(a[id])) {
            int p = a[id];
            done.insert(p);
            for (auto& it : jumps[p]) {
                if (d[it] == - 1) {
                    d[it] = d[id] + 1;
                    q.push(it);
                }
            }
        }
    }
    return d[n - 1];
}

vector<int> build_spf() {
    vector<int> spf(mxx + 1);
    for (int i = 0; i <= mxx; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= mxx; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mxx; j+= i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    } 
    return spf;
}
 
const vector<int> spf = build_spf();

int minJumps(vector<int>& a) {
    int n = a.size();
    vector<int> d(n, -1);
    queue<int> q;
    unordered_set<int> seen;
    unordered_map<int, vector<int>> jumps;
    for (int i = 0; i < n; i++) {
        int val = a[i];
        while (val > 1) {
            int p = spf[val];
            jumps[p].push_back(i);
            while (val % p == 0) val /= p; 
        }
    }
    d[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int id = q.front();
        q.pop();
        if (id - 1 >= 0 && d[id - 1] == -1) {
            d[id - 1] = d[id] + 1;
            q.push(id - 1);
        }
        if (id + 1 < n && d[id + 1] == -1) {
            d[id + 1] = d[id] + 1;
            q.push(id + 1);
        }
        if (!seen.contains(a[id]) && spf[a[id]] == a[id]) {
            int p = a[id];
            seen.insert(p);
            for (auto& it: jumps[p]) {
                if (d[it] == -1) {
                    d[it] = d[id] + 1;
                    q.push(it);
                }
            }
        }
    }
    return d[n - 1];
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
        cout << minJumps(a) << '\n';
    }
    return 0;
}