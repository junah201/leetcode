// 104. Maximum Depth of Binary Tree
//

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

class Solution
{
public:
    int ans;
    void get(TreeNode *node, int deep)
    {
        if (node == nullptr)
            return;
        if (deep > ans)
            ans = deep;
        if (node->left != nullptr)
            get(node->left, deep + 1);
        if (node->right != nullptr)
            get(node->right, deep + 1);
    }
    int maxDepth(TreeNode *root)
    {
        ans = 0;
        get(root, 1);
        return ans;
    }
};