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

int longestSubstr(string s, int m) {
    if (m <= 1)
        return m;
    vector<int> cnt(260, 0);
    int cur = 0;
    int max_val = 0;
    int pre = 0;
    for (int i = 0; i < s.size(); i++) {
        if (cnt[s[i]] == 0) {
            cur++;
        }
        cnt[s[i]]++;
        while (cur > m) {
            cnt[s[pre]]--;
            if (cnt[s[pre]] == 0)
                cur--;
            pre++;
        }
        max_val = max(i - pre + 1, max_val);
    }
    cout << max_val << endl;
    return max_val;
}
int main() {
    string s = "abcdbcedf";
    longestSubstr(s, 3);
    return 0;
}
