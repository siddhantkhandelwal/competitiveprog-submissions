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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (!root)
        {
            return {};
        }
        q.push(root);
        vector<vector<int>> levels;
        while (!q.empty())
        {
            int l = q.size();
            vector<int> lev;
            while (l--)
            {
                TreeNode *temp = q.front();
                q.pop();
                lev.push_back(temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            levels.push_back(lev);
        }
        return levels;
    }
};