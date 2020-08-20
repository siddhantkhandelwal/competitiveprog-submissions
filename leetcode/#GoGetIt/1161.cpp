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
    int maxLevelSum(TreeNode *root)
    {
        int ans;
        int maxSum = INT_MIN;
        int lId = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            int n = q.size();
            int sum = 0;
            while (n--)
            {
                TreeNode *t = q.front();
                q.pop();
                if (t->left)
                {
                    q.push(t->left);
                }
                if (t->right)
                {
                    q.push(t->right);
                }
                sum += t->val;
            }
            if (maxSum < sum)
            {
                maxSum = sum;
                ans = lId;
            }
            lId++;
        }
        return ans;
    }
};