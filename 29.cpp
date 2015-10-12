#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;

void wallsAndGates(vector<vector<int>>& rooms) {
    int n = rooms.size();
    if (n == 0)
        return ;
    int m = rooms[0].size();
    if (m == 0)
        return ;
    queue<pair<int, int> > que;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (rooms[i][k] == 0) {
                que.push({i, k});
            }
        }
    }
}
int main() {
    int INF = INT_MAX;
    vector<vector<int>> rooms = {
        {
            {INF,-1,0,INF},
            {INF,INF,INF,  -1},
            {INF,-1,INF,  -1},
             {0,-1,INF,INF}
        }
    };
    wallsAndGates(rooms);
    for (auto k : rooms) {
        for (auto i : k) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
