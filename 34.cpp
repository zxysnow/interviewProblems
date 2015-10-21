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

string multiply(string num1, string num2) {
    int n = num1.size(), m = num2.size();
    string ans(n + m, '0');
    for (int i = n - 1; i >= 0; i--) {
        for (int k = m - 1; k >= 0; k--) {
            int idx = n - 1 - i + m - 1 - k;
            int val = ans[idx] - '0' + (num1[i] - '0') * (num2[k] - '0');
            ans[idx] = '0' + val % 10;
            ans[idx + 1] += val / 10;
        }
    }
    int k = n + m - 1;
    while (k != 0 && ans[k] == '0')
        k--;
    string a = ans.substr(0, k + 1);
    reverse(a.begin(), a.end());
    return a;
}
int main() {
    string a, b;
    cin >> a >> b;
    cout << multiply(a, b);
    return 0;
}
