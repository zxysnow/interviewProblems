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
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode *parent;
     TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
     TreeNode(int x, TreeNode *parent, TreeNode *left, TreeNode *right) {
        val = x;
        parent = parent;
        left = left;
        right = right;
     }
 };

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        this->root = root;
        pushLeft();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return root != NULL;
    }

    /** @return the next smallest number */
    int next() {
        int val = root->val;
        if (root->right != NULL) {
            root = root->right;
            pushLeft();
            return val;
        }
        TreeNode* parent = root->parent;
        while (parent && root == parent->right) {
            root = parent;
            parent = root->parent;
        }
        root = parent;
        return val;
    }

private :
    TreeNode *root;
    void pushLeft() {
        while (root->left) {
            root = root->left;
        }
    }
};
int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->parent = root;
    root->right->parent = root;
    TreeNode *five = root->right;
    five->right = new TreeNode(7);
    five->right->parent = five;
    TreeNode *two = root->left;
    two->left = new TreeNode(1);
    two->right = new TreeNode(3);
    two->left->parent = two;
    two->right->parent = two;
    BSTIterator it(root);
    while (it.hasNext()) {
        cout << it.next() << endl;
        system("pause");
    }
    return 0;
}
