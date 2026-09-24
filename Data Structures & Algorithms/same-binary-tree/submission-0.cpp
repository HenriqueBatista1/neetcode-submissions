/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int dfs(TreeNode* p, TreeNode *q) {
        if(p == nullptr && q == nullptr) {
            return 0;
        }
        else if((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) 
        {
            return -1;
        }

        dfs(p->left, q->left);
        if(dfs(p->left, q->left) == -1) return -1;
        dfs(p->right, q->right); 
        if(dfs(p->right, q->right) == -1) return -1;

        if(p->val != q->val) return -1;
        else return 0;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q) != -1;
    }
};
