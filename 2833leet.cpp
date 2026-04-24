#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

int furthestDistanceFromOrigin(string moves) {
    int n = moves.length();
    int dist = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (moves[i] == 'L') {
            dist--;
        }
        else if (moves[i] == 'R') {
            dist++;
        }
        else {
            count++;
        }
    }
    if (dist >= 0) {
        dist += count;
    }
    else {
        dist -= count;
        dist *= -1;
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        string moves;
        cin >> moves;
        cout << furthestDistanceFromOrigin(moves) << '\n';
    }
    return 0;
}