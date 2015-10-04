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

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        bs[0] = v1.begin(), bs[1] = v2.begin();
        es[0] = v1.end(), es[1] = v2.end();
        p = 0;
    }

    int next() {
        p ^= 1;
        if (bs[1] == es[1] || p == 1 && bs[0] != es[0]) {
            return *bs[0]++;
        }
        return *bs[1]++;
    }

    bool hasNext() {
        return bs[0] != es[0] || bs[1] != es[1];
    }
private:
    int p;
    vector<int>::iterator bs[2], es[2];
};
int main() {
    vector<int> v1 = {1, 2};
    vector<int> v2 = {4, 5, 6};
    ZigzagIterator zig(v1, v2);
    while (zig.hasNext()) {
        cout << zig.next() << endl;
    }
    return 0;
}
