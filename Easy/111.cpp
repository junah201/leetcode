// 111. Minimum Depth of Binary Tree
// 02/25/2022 20:37	Accepted	366 ms	144.4 MB	cpp

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
        if (node == nullptr || node->left == nullptr && node->right == nullptr)
        {
            if (deep < ans)
                ans = deep;
            return;
        }
        if (node->left != nullptr)
            get(node->left, deep + 1);
        if (node->right != nullptr)
            get(node->right, deep + 1);
    }
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        ans = 987654321;
        get(root, 1);
        return ans;
    }
};