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
    int pathSum(TreeNode *root, int sum)
    {
        if (!root)
        {
            return 0;
        }
        return findPaths(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:
    int findPaths(TreeNode *node, int sum)
    {
        if (!node)
            return 0;
        return (node->val == sum) + findPaths(node->left, sum - node->val) + findPaths(node->right, sum - node->val);
    }
};