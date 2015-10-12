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
#include <time.h>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;

class Node {
public :
    int val;
    Node *left, *right;
    Node(int val) : val(val), left(NULL), right(NULL) {};
};
map<int, vector<int> > mp;
void verticalOrder(Node *root, int h) {
    if (root == NULL)
        return ;
    mp[h].push_back(root->val);
    verticalOrder(root->left, h - 1);
    verticalOrder(root->right, h + 1);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    cout << "Vertical order traversal is \n";
    verticalOrder(root, 0);

    for (auto k : mp) {
        for (auto i : k.second) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
