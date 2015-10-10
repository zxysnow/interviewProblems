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
#include <stack>
#include <queue>

using namespace std;

class Node {
public :
    Node *left, *right;
    int val;
    Node(int val) : val(val) {
        left = right = NULL;
    }
};

bool check(string s) {
    int cnt = 0, op = 0;
    for (auto ch : s) {
        if (ch == '(') {
            cnt++;
            continue;
        }
        if (ch == ')') {
            cnt--;
            op--;
            continue;
        }
        if (ch == '-' || ch == '+' || ch == '*') {
            op++;
            if (op != cnt) {
                return false;
            }
            continue;
        }
        if (cnt < 0)
            return false;
        if (!isdigit(ch) && ch != '+' && ch != '-' && ch != '*' && ch != ' ') {
            return false;
        }
    }
    if (cnt != 0)
        return false;

    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == '(' && isdigit(s[i]))
            return false;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            i++;
            int cnt = 0;
            while (i < s.size() && isdigit(s[i]) || s[i] == ' ') {
                if (s[i] == ' ')
                    cnt++;
                i++;
            }
            if (cnt >= 2)
                return false;
            i--;
        }
    }
    return true;
}
    int calcWithOp(int a, int b, char op) {
        switch (op) {
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            case '/' : return a / b;
        }
    }
int k;
int dfs(int t, char c, string &s) {
    vector<int> num;
    int i = 0;
    while (k < s.size() && s[k] != ')') {
        if (s[k] == '(') {
            k++;
            char ch = s[k];
            int p = dfs(t + 1, ch, s);
            num.push_back(p);
        } else if (isdigit(s[k])) {
            int n = 0;
            while (k < s.size() && isdigit(s[k])) {
                n = n * 10 + s[k] - '0';
                k++;
            }
            num.push_back(n);
        } else {
            k++;
        }
    }
    int ans = num[0];
    for (int i = 1; i < num.size(); i++) {
        ans = calcWithOp(ans, num[i], c);
    }
    k++;
    if (num.size() == 1) {
        if (c == '-')
            ans *= -1;
    }
    return ans;
}
int main() {
    int T;
    cin >> T;
    getchar();
    while(T--) {
        string s;
        getline(cin, s);
        string ss;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (ss.size() > 0 && isdigit(ss.back()) && i + 1 < s.size() && isdigit(s[i + 1])) {
                    ss += ' ';
                }
                continue;
            }
            ss += s[i];
        }
        if (!check(ss)) {
            cout << "invalid expression" << endl;
            continue;
        }
        s = ss;
        k = 0;
        while (s[k] != '(')
            k++;
        cout << dfs(k, s[k], s) << endl;
    }

    return 0;
}
