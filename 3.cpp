#include <set>
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

class TreeNode {
public :
    TreeNode *left, *right;
    int val;
    TreeNode (int _val = 0, TreeNode* _left = NULL, TreeNode* _right = NULL) : val(_val), left(_left), right(_right) {}
};
void serialize(TreeNode *root, vector<int> &ans) {
    if (root == NULL) {
        ans.push_back(-1);
        return ;
    }
    ans.push_back(root->val);
    serialize(root->left, ans);
    serialize(root->right, ans);
}
TreeNode* deserialize(vector<int> &ans, int &x) {
    if (ans[x] == -1) {
        x++;
        return NULL;
    }
    TreeNode *p = new TreeNode(ans[x++]);
    p->left = deserialize(ans, x);
    p->right = deserialize(ans, x);
    return p;
}
void traversal(TreeNode *root) {
    if (root == NULL) {
        cout << -1 <<endl;
        return ;
    }
    cout << root->val << endl;
    traversal(root->left);
    traversal(root->right);
}
int main() {
    TreeNode root(0, new TreeNode(1, NULL, new TreeNode(3)), new TreeNode(4));
    vector<int> ans;
    serialize(&root, ans);
    for (auto k : ans)
        cout << k << ' ';
    cout << endl;
    int x = 0;
    TreeNode *p = deserialize(ans, x);
    traversal(p);
    return 0;
}
