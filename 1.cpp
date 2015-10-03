#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <fstream>
#include <map>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

class Char {
public :
    char ch;
    int f;
    Char(char ch, int f) : ch(ch), f(f) {}
};
int findPos(vector<Char> &fun, vector<int> &dis, int min_distance, int pos) {
    int max_f = -1, max_pos = -1;
    for (int i = 0; i < dis.size(); i++) {
        if (pos - dis[i] >= min_distance && fun[i].f > max_f) {
            max_f = fun[i].f;
            max_pos = i;
        }
    }
    return max_pos;
}
bool findPermutation(string v, int min_distance, string &ans) {
    vector<int> cnt(256, 0);
    vector<Char> fun;
    for (char ch : v) {
        cnt[ch]++;
    }
    for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i] != 0) {
            fun.push_back(Char(i, cnt[i]));
        }
    }
    vector<int> dis(fun.size(), -min_distance);
    for (int i = 0; i < v.size(); i++) {
        int pos = findPos(fun, dis, min_distance, i);
        if (pos == -1)
            return false;
        ans += fun[pos].ch;
        fun[pos].f--;
        dis[pos] = i;
    }
    return true;
}
int main() {
    int n = 10000;
    srand(time(NULL));
    int cnt = 0;
    while (n--) {
        int m = rand() % 100 + 10;
        string s = "";
        while (m--) {
            s += rand() % 26 + 'a';
        }
        for (int d = 1; d < s.size()/ 2; d++) {
            string ans;
            if (findPermutation(s, d, ans)) {
                cout << cnt++ << ' ' << d << endl;
               // cout << s << endl << d << endl <<ans <<endl;
                vector<int> pos(256, -1);
                for (int i = 0; i < ans.size(); i++) {
                    if (pos[ans[i]] == -1)
                        continue;
                    if (i - pos[ans[i]] < d) {
                        cout <<"ERROR!!!!" <<endl;
                        system("pause");
                    }
                }
            }
        }
    }
    return 0;
}
