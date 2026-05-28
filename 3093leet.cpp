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

struct TrieNode {
    int t[26];
    int best = -1;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            t[i] = -1;
        }
    }
};

class Trie {
private:
    vector<TrieNode> nodes;

    bool comp(vector<string>& a, int i, int j) {
        if (j == -1)
            return true;
        if (a[i].size() != a[j].size()) {
            return a[i].size() < a[j].size();
        }
        return i < j;
    }

public:
    Trie() { nodes.push_back(TrieNode()); }

    void insert(string str, int idx, vector<string>& a) {
        reverse(str.begin(), str.end());
        int curr = 0;
        if (comp(a, idx, nodes[curr].best)) {
            nodes[curr].best = idx;
        }
        for (int i = 0; i < str.size(); i++) {
            int id = str[i] - 'a';
            if (nodes[curr].t[id] == -1) {
                nodes[curr].t[id] =
                    nodes.size(); // so goes from like 0 to 1 now
                nodes.push_back(TrieNode());
            }
            curr = nodes[curr].t[id];
            if (comp(a, idx, nodes[curr].best)) {
                nodes[curr].best = idx;
            }
        }
    }

    int ans(string str) {
        reverse(str.begin(), str.end());
        int curr = 0;
        for (int i = 0; i < str.size(); i++) {
            int id = str[i] - 'a';
            if (nodes[curr].t[id] == -1) {
                break;
            }
            curr = nodes[curr].t[id];
        }
        return nodes[curr].best;
    }
};

vector<int> stringIndicies(vector<string>& a, vector<string>& b) {
    Trie T;
    vector<int> sol;
    for (int i = 0; i < a.size(); i++) {
        T.insert(a[i], i, a);
    }
    for (int i = 0; i < b.size(); i++) {
        sol.push_back(T.ans(b[i]));
    }
    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, n;
        cin >> m >> n;
        vector<string> a(m), b(n);
        for (int i = 0; i < m; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<int> ans = stringIndicies(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}