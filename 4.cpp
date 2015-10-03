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
void findLongest(TreeNode *root, int len, int pre, int &max_len, int &tail) {
    if (root == NULL) {
        return ;
    }
    if (len == 0 || root->val != pre + 1) {
        len = 1;
    } else {
        len += 1;
    }
    if (max_len < len) {
        max_len = len;
        tail = root->val;
    }
    findLongest(root->left, len, root->val, max_len, tail);
    findLongest(root->right, len, root->val, max_len, tail);
}
int main() {
    TreeNode root(0, new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(3)), new TreeNode(3)), new TreeNode(4));
    vector<int> arr = {2, -1, 3, 1, 2, 3, 4, -1, -1, -1, -1, -1, 4, -1, 5, -1, -1};
    int x = 0;
    TreeNode *p = deserialize(arr, x);
    traversal(p);
    int max_len = 1, tail = root.val;
    findLongest(p, 0, 0, max_len, tail);
    for (int i = tail - max_len + 1; i <= tail; i++) {
        cout << i << "-->";
    }
    return 0;
}
