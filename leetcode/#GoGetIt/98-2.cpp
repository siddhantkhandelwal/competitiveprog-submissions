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
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = new TreeNode(INT_MIN);

public:
    bool isValidBST(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        help(root);
        if (first && second)
        {
            return false;
        }
        return true;
    }

    void help(TreeNode *root)
    {
        if (root == NULL)
            return;
        help(root->left);
        if (first == NULL && prev->val > root->val)
            first = prev;
        if (first != NULL && prev->val > root->val)
            second = root;
        prev = root;
        help(root->right);
    };
}