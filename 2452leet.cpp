#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;} 

vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
    int n = q[0].size();
    vector<string> sol;
    for (int i = 0; i < q.size(); i++) {
        for (int j = 0; j < d.size(); j++) {
            int dist = 0;
            for (int id = 0; id < n; id++) {
                if (q[i][id] != d[j][id]) {
                    dist++;
                }
                if (dist > 2) {
                    break;
                }
            }
            if (dist <= 2) {
                sol.push_back(q[i]);
                break;
            }
        }
    }
    return sol;
}

vector<string> twoEditWordsTLE(vector<string>& q, vector<string>& d) {
    int a = q.size();
    int b = d.size();
    vector<string> sol;
    unordered_map <string, bool> mp;
    for (int i = 0; i < b; i++) {
        mp[d[i]] = true;
    }
    for (int i = 0; i < a; i++) {
        string str = q[i];
        int len = str.length();
        bool good = false;
        if (mp[str]) {
            sol.push_back(str);
            continue;
        }
        for (int j = 0; j < len; j++) {
            char old1 = str[j];
            for (int k = 0; k < 26; k++) {
                char c1 = 'a' + k;
                str[j] = c1;
                if (mp[str]) {
                    good = true;
                    break;
                }
                for (int l = 0; l < len; l++) {
                    char old2 = str[l];
                    for (int m = 0; m < 26; m++) {
                        char c2 = 'a' + m;
                        str[l] = c2;
                        if (mp[str]) {
                            good = true;
                            break;
                        } 
                    }
                    str[l] = old2;
                    if (good) break;
                }
                if (good) break;
            }
            str[j] = old1;
            if (good) break;
        }
        if (good) {
            sol.push_back(q[i]);
        }
    }
    return sol;
}

vector<string> twoEditWords1(vector<string>& q, vector<string>& d) {
    vector<string> sol;
    int a = q.size();
    int b = d.size();
    unordered_set<string> s;
    for (int i = 0; i < b; i++) {
        string curr = d[i];
        s.insert(curr);
        int len = curr.length();
        for (int j = 0; j < len; j++) {
            curr[j] = '*';
            s.insert(curr);
            curr = d[i];
        }
        curr = d[i];
        for (int j = 0; j < len; j++) {
            curr[j] = '*';
            string ncurr = curr;
            for (int k = j + 1; k < len; k++) {
                curr[k] = '*';
                s.insert(curr);
                curr = ncurr;
            }
            curr = d[i];
        }
    }
    for (int i = 0; i < a; i++) {
        string curr = q[i];
        int len = curr.length();
        if (s.count(curr)) {
            sol.push_back(q[i]);
            continue;
        }
        bool good = false;
        for (int j = 0; j < len; j++) {
            curr[j] = '*';
            if (s.count(curr)) {
                sol.push_back(q[i]);
                good = true;
                break;
            } else {
                curr = q[i];
            }
        }
        if (good)
            continue;
        curr = q[i];
        for (int j = 0; j < len; j++) {
            curr[j] = '*';
            string ncurr = curr;
            bool good1 = false;
            for (int k = j + 1; k < len; k++) {
                curr[k] = '*';
                if (s.count(curr)) {
                    sol.push_back(q[i]);
                    good1 = true;
                    break;
                } else {
                    curr = ncurr;
                }
            }
            if (good1)
                break;
            curr = q[i];
        }
    }
    return sol;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        vector<string> q(a), d(b), sol;
        for (int i = 0; i < a; i++) cin >> q[i];
        for (int i = 0; i < b; i++) cin >> d[i];
        sol = twoEditWords(q, d);
        for (int i = 0; i < sol.size(); i++) {
            cout << sol[i] << (i == sol.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}