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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        vector<string> v;
        string s;
        helper(root, v, s);
        return v;
    }
    void helper(TreeNode *root, vector<string> &v, string s)
    {
        if (!root)
        {
            return;
        }
        if (s.length())
        {
            s += "->" + to_string(root->val);
        }
        else
        {
            s = to_string(root->val);
        }
        if (!(root->left) && !(root->right))
        {
            v.push_back(s);
            return;
        }
        helper(root->left, v, s);
        helper(root->right, v, s);
    }
};