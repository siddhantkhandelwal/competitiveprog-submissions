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
    void helper(TreeNode *root, int &minDiff, int &res)
    {
        if (!root)
        {
            return;
        }
        helper(root->left, minDiff, res);
        if (minDiff != -1)
        {
            res = min(res, root->val - minDiff);
        }
        minDiff = root->val;
        helper(root->right, minDiff, res);
    }
    int minDiffInBST(TreeNode *root)
    {
        int res = INT_MAX;
        int pre = -1;
        helper(root, pre, res);
        return res;
    }
};