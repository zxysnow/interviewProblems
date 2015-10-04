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

class Iterator {
public :
    Iterator() {}
    Iterator(vector<int> &v) {
        _begin = v.begin();
        _end = v.end();
        cnt = 0;
    }
    bool hasNext() {
        while (_begin != _end && cnt == 0) {
            val = *_begin++;
            if (_begin == _end)
                break;
            cnt = *_begin++;
        }
        return cnt != 0 || _begin != _end;
    }
    int next() {
        if (cnt != 0) {
            cnt--;
            return val;
        }
        while (cnt == 0) {
            val = *_begin++;
            cnt = *_begin++;
        }
        cnt--;
        return val;
    }
private :
    vector<int>::iterator _begin, _end;
    int cnt;
    int val;
};
int main() {
    vector<int> v = {4,2,5,0,2,4};
    Iterator it(v);
    while (it.hasNext()) {
        cout << it.next() << endl;
    }
    return 0;
}
