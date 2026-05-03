#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

bool rotateString1(string s, string goal) {
    int a = s.length();
    int b = goal.length();
    if (a != b) return false;
    s += s;
    a *= 2;
    int k = 0;
    for (int i = 0; i < a; i++) {
        int t = i;
        while (i < a && k < b && s[i] == goal[k]) {
            i++;
            k++;
        }
        if (k == b) {
            return true;
        }
        else {
            k = 0;
            i = t;
        }
    }
    return false;
}


bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) return false;
    s += s;
    return s.find(goal) != string::npos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        string s, goal;
        cin >> s >> goal;
        cout << (rotateString(s, goal) ? "True" : "False") << '\n';
    }
    return 0;
}