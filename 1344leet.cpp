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

double angleClock(int hour, int minutes) { 
    hour %= 12;
    minutes %= 60;
    ld theta1 = (2 * PI * hour) / (ld)12;
    ld theta2 = (2 * PI * minutes) / (ld)60;
    ld per = 0;
    if (minutes != 0)
        per = minutes / (ld)60;
    theta1 += ((2 * PI) / 12) * per;
    auto deg = [&](ld val) { return val * 180 / PI; };
    ld ans = acos(cos(theta1) * cos(theta2) + sin(theta1) * sin(theta2));
    return deg(ans);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int h, m;
        cin >> h >> m;
        cout << angleClock(h, m) << '\n';
    }
    return 0;
}