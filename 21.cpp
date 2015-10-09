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
#include <unordered_map>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;

vector<int> findKthVector(vector<int> &p, vector<int> &a, int k) {
    int n = p.size();
    unordered_map<int, pair<int, int> > cid;
    vector<vector<int> > cycle;
    vector<bool> visit(n, false);
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            vector<int> c;
            c.resize(0);
            int pre = i;
            int t = i;
            do {
                visit[t] = true;
                cid[t] = make_pair(cycle.size(), c.size());
                c.push_back(t);
                t = p[t];
            } while (t != i);
            cycle.push_back(c);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int t = a[i];
        int ci = cid[t].first;
        int pi = cid[t].second;
        int c_len = cycle[ci].size();
        int idx = (pi + c_len + k) % c_len;
        ans.push_back(cycle[ci][idx]);
    }
    for (auto e : ans)
        cout << e <<' ';
    return ans;
}
int main() {
    vector<int> p = {4, 6, 1, 5, 3, 7, 2, 0};
    vector<int> a = {3, 1, 6, 4, 2, 7, 0, 3};
    findKthVector(p, a, 1);
    return 0;
}
