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
    vector<int> largestValues(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (!root)
        {
            return {};
        }
        q.push(root);
        vector<int> res;
        while (!q.empty())
        {
            int l = q.size();
            int t = INT_MIN;
            while (l--)
            {
                TreeNode *temp = q.front();
                q.pop();
                t = max(t, temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            res.push_back(t);
        }
        return res;
    }
};