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
    vector<TreeNode *> generateTrees(int n)
    {
        if (!n)
        {
            return vector<TreeNode *>();
        }
        return helper(1, n);
    }
    vector<TreeNode *> helper(int start, int end)
    {
        vector<TreeNode *> res;
        if (start > end)
        {
            res.push_back(NULL);
            return res;
        }
        else if (start == end)
        {
            res.push_back(new TreeNode(start));
            return res;
        }
        else
        {
            for (int i = start; i <= end; i++)
            {
                auto left = helper(start, i - 1);
                auto right = helper(i + 1, end);
                for (auto lnode : left)
                {
                    for (auto rnode : right)
                    {
                        TreeNode *root = new TreeNode(i);
                        root->left = lnode;
                        root->right = rnode;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};