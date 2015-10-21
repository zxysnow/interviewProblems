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

void Sort(vector<int> &a) {
    for (int i = 1; i < a.size(); i++) {
        if ((i & 1) && a[i] < a[i - 1] || (i & 1) == 0 && a[i] > a[i - 1])
            swap(a[i], a[i - 1]);
    }
}
int main() {
    int n;
    vector<int> a;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    Sort(a);
    for (auto k : a)
        cout << k  << ' ';
    return 0;
}
