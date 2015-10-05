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

int main() {

    queue<int> que;
    int k = 2;
    int n;
    int sum = 0;
    while (cin >> n) {
        que.push(n);
        sum += n;
        if (que.size() > k ) {
            sum -= que.front();
            que.pop();
        }
        if (que.size() == k) {
            cout << sum * 1.0 / k << endl;
        }
    }

    return 0;
}
