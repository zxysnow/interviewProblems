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

vector<int> slideWindow(vector<int> &a, int k) {
    deque<int> que;
    vector<int> ans;
    for (int i = 0; i < a.size(); i++) {
        while (!que.empty() && i - que.front() >= k) {
            que.pop_front();
        }
        while (!que.empty() && a[que.back()] < a[i]) {
            que.pop_back();
        }
        que.push_back(i);
        if (i >= k - 1)
            ans.push_back(a[que.front()]);
    }
    for (auto e : ans)
        cout << e << endl;
    return ans;
}
int main() {
    vector<int> a = {9,1,7,6,3,2};
    slideWindow(a, 2);
    return 0;
}
