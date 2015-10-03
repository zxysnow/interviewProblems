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

int findTriplets(vector<int> &a, int t) {
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        int cur = t - a[i];
        int l = i + 1, r = a.size() - 1;
        while (l < r) {
            if (a[l] + a[r] <= cur) {
                ans += (r - l);
                l++;
            } else {
                r--;
            }
        }
    }
    return ans;
}
int main() {
    vector<int> a = {3, 3, 4, 6, 8};
    cout << findTriplets(a, 13);
    return 0;
}
