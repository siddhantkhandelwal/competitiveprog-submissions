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
private:
    int result;

public:
    void solve(TreeNode *root, int maxVal)
    {
        if (maxVal <= root->val)
        {
            result++;
            maxVal = root->val;
        }
        if (root->left)
        {
            solve(root->left, maxVal);
        }
        if (root->right)
        {
            solve(root->right, maxVal);
        }
    }
    int goodNodes(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        if (!(root->left) && !(root->right))
        {
            return 1;
        }
        result = 0;
        solve(root, root->val);
        return result;
    }
};