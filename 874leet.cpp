#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

int distance(tuple<int, int, int>& pos) {
    auto& [a, b, c] = pos;
    return a * a + b * b;
}

bool check(unordered_map<pair<int, int>, bool, pair_hash>& obstacles,
           tuple<int, int, int>& pos) {
    auto& [x, y, o] = pos;
    pair<int, int> p = {x, y};
    if (obstacles.find(p) != obstacles.end()) {
        if (o == 1) {
            y -= 1;
        } else if (o == 2) {
            x += 1;
        } else if (o == 3) {
            y += 1;
        } else {
            x -= 1;
        }
        return true;
    }
    return false;
}

void move(tuple<int, int, int>& p, int command,
          unordered_map<pair<int, int>, bool, pair_hash>& obs, int& dist) {
    auto& [a, b, c] = p;
    if (command == -1) {
        c = (c + 3) % 4;
    } else if (command == -2) {
        c = (c + 1) % 4;
    } else {
        while (command) {
            if (c == 1) {
                b += 1;
            } else if (c == 2) {
                a -= 1;
            } else if (c == 0) {
                a += 1;
            } else {
                b -= 1;
            }
            if (check(obs, p))
                return;
            dist = max(dist, distance(p));
            command--;
        }
    }
}

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int a = commands.size();
    int b = obstacles.size();
    tuple<int, int, int> p = {0, 0, 1};
    unordered_map<pair<int, int>, bool, pair_hash> mp;
    for (int i = 0; i < b; i++) {
        pair<int, int> p = {obstacles[i][0], obstacles[i][1]};
        mp[p] = true;
    }
    int dist = 0;
    for (int i = 0; i < a; i++) {
        move(p, commands[i], mp, dist);
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt; 
    while (tt--) {
        int a, b;
        cin >> a >> b;
        vector<int> commands(a);
        vector<vector<int>> obstacles(b, vector<int> (2));
        for (int i = 0; i < a; i++) cin >> commands[i];
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> obstacles[i][j];
            }
        } 
        cout << robotSim(commands, obstacles) << '\n';
    }
    return 0;
}