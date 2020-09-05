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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<pair<TreeNode *, int>> s;
        s.push(make_pair(root, 0));
        vector<int> ans;
        while (!s.empty())
        {
            auto t = s.top();
            s.pop();
            if (t.second == 3 || !(t.first))
            {
                continue;
            }
            s.push(make_pair(t.first, t.second + 1));
            if (t.second == 0)
            {
                if (t.first->left)
                    s.push(make_pair(t.first->left, 0));
            }
            else if (t.second == 1)
            {
                if (t.first->right)
                    s.push(make_pair(t.first->right, 0));
            }
            else if (t.second == 2)
            {
                ans.push_back(t.first->val);
            }
        }
        return ans;
    }
};