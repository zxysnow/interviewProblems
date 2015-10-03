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

const int MAX = 1000;

int c[MAX][MAX];
int lowbit(int x) {
    return x & (-x);
}
void setValue(int x, int y, int v) {
    for (int i = x; i < MAX; i += lowbit(i)) {
        for (int k = y; k < MAX; k += lowbit(k)) {
            c[i][k] += v;
        }
    }
}
void Updata(int x,int num)// num 可能都为1，具体问题具体分析
{
	int i;
	for(i=x; i>0; i-=lowbit(i)) {
        cout << i <<endl;
        string s;
        int t = i;
        while (t) {
            s += '0' + t % 2;
            t /= 2;
        }
        reverse(s.begin(), s.end());
        cout << s <<endl;
    //    c[i] += num;	// 若num 为1，c[i]++
	}

}

int sum(int x, int y) {
    int rst = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        for (int k = y; k > 0; k -= lowbit(k)) {
            rst += c[i][k];
        }
    }
    return rst;
}
int main() {
    int n;
    while (cin >> n)
    Updata(n, 10);
    string s;
    int x, y, v;
    while (cin >> s) {
        cin >> x >> y;
        if (s == "set") {
            cin >> v;
            setValue(x, y, v);
        } else {
            int ans = sum(x, y);
            cout << ans << endl;
        }
    }
    return 0;
}
