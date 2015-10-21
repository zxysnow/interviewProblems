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

const int MAX = 110;
int a[MAX][MAX];
int dp[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int dfs(int x, int y) {
    if (dp[x][y])
        return dp[x][y];
    int max_len = 0;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
            if (a[xx][yy] < a[x][y]) {
                max_len = max(max_len, dfs(xx, yy));
            }
        }
    }
    dp[x][y] = max_len + 1;
    return max_len + 1;
}
int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++)
                cin >> a[i][k];
        }
        memset(dp, 0, sizeof(dp));
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                if (!dp[i][k]) {
                    dp[i][k] = dfs(i, k);
                }
                max_len = max(max_len, dp[i][k]);
            }
        }
        cout << max_len << endl;
    }
    return 0;
}
