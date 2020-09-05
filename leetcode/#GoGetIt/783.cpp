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
    void helper(TreeNode *root, int &minDiff)
    {
        if (!root)
        {
            return;
        }
        helper(root->left, pre, res);
        if (pre != -1)
        {
            res = min(res, root->val - pre);
        }
        pre = root->val;
        helper(root->right, pre, res);
    }
    int minDiffInBST(TreeNode *root)
    {
        int res = INT_MAX;
        int pre = -1;
        helper(root, pre, res);
        return res;
    }
};