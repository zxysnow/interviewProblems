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

const double eps = 1e-10;

double sqrtWithPrecision(int n) {
    if (n < 0)
        return -1;
    double t = n;
    double l = 0, r = n;
    while (l < r) {
        double mid = l + (r - l) / 2;
        double p = mid * mid;
        if (abs(p - n) < eps) {
            return mid;
        }
        if (p > n) {
            r = mid;
        } else {
            l = mid;
        }
    }
}
int main() {
    int n;
    while (cin >> n){
        cout << sqrtWithPrecision(n) << endl;
    }
    return 0;
}
