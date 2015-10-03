#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <fstream>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

bool canConnect(int x1, int y1, int x2, int y2, vector<bool> &visit) {
    if ((x1 & 1) == (x2 & 1) && (y1 & 1) == (y2 & 1) && !visit[(x1 + x2) / 2 * 3 + (y1 + y2) / 2])
        return false;
    return true;
}
int gcd(int m, int n) {
    return n == 0 ? m : gcd(n, m % n);
}
bool canConnect(int x1, int y1, int x2, int y2, vector<bool> &visit, int m, int n) {
    int deltax = x2 - x1;
    int deltay = y2 - y1;
    int k;
    if (deltax == 0) {
        k = abs(deltay);
    } else if (deltay == 0) {
        k = abs(deltax);
    } else {
        k = gcd(abs(deltax), abs(deltay));
    }
    deltax /= k;
    deltay /= k;
    for (int px = x1 + deltax, py = y1 + deltay; !(px == x2 && py == y2); px += deltax, py += deltay) {
        if (!visit[px * m + py])
            return false;
    }
    return true;
}
class NODE {
public :
    int state, pos;
    NODE(int _state = 0, int _pos = 0) : state(_state), pos(_pos) {}
};
bool canConnect(int state, int x, int y) {
    int x1 = x / 3;
    int y1 = x % 3;
    int x2 = y / 3;
    int y2 = y % 3;
    if ((x1 & 1) == (x2 & 1) && (y1 & 1) == (y2 & 1) && (state & (1 << ((x1 + x2) / 2 * 3 + (y1 + y2) / 2))) == 0)
        return false;
    return true;
}
void dfs(vector<int> &now, vector<vector<int> > &ans, vector<bool> &visit) {
    if (now.size() >= 4) {
        ans.push_back(now);
    }
    if (now.size() == 9)
        return ;
    for (int i = 0; i < 9; i++) {
        if (visit[i] || now.size() > 0 && i == now.back())
            continue;
        int x1 = i / 3;
        int y1 = i % 3;
        if (now.size() == 0 || canConnect(now.back() / 3, now.back() % 3, x1, y1, visit)) {
            now.push_back(i);
            visit[i] = true;
            dfs(now, ans, visit);
            visit[i] = false;
            now.pop_back();
        }
    }
}

int lengthOfState(int n) {
    int len = 0;
    while (n) {
        n &= (n - 1);
        len++;
    }
    return len;
}
int main() {
    queue<NODE> q;
    int dp[1024][10];
    bool visit[1024][10];
    int ans = 0;
    memset(visit, 0, sizeof(visit));
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 9; i++) {
        q.push(NODE(1 << i, i));
        dp[1 << i][i] = 1;
    }
    while (!q.empty()) {
        NODE cur = q.front();
        q.pop();
        int state = cur.state, pos = cur.pos;
        if (visit[state][pos])
            continue;
        visit[state][pos] = true;
        for (int i = 0; i < 9; i++) {
            if ((state & (1 << i)) == 0) {
                if (canConnect(state, pos, i)) {
                    dp[state | (1 << i)][i] += dp[state][pos];
                    q.push(NODE(state | (1 << i), i));
                }
            }
        }
        if (lengthOfState(state) >= 4) {
            ans += dp[state][pos];
        }
    }
    cout << ans << endl;
    return 0;
}
