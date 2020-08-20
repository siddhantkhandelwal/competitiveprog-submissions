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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (!root)
        {
            return -1;
        }
        q.push(root);
        int res;
        while (!q.empty())
        {
            int l = q.size();
            int i = 0;
            while (i++ < l)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (i == 1)
                    res = temp->val;
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        return res;
    }
};