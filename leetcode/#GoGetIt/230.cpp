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
    int kthSmallest(TreeNode *root, int k)
    {
        if (!root || k < 1)
        {
            return -1;
        }
        stack<pair<TreeNode *, int>> st;
        st.push(make_pair(root, 0));
        vector<int> ans;
        while (!st.empty())
        {
            auto n = st.top();
            st.pop();
            auto t = n.first;
            auto s = n.second;
            if (t == NULL || s == 3)
            {
                continue;
            }
            st.push(make_pair(t, s + 1));
            if (s == 0)
            {
                st.push(make_pair(t->left, 0));
            }
            else if (s == 1)
            {
                ans.push_back(t->val);
            }
            else if (s == 2)
            {
                st.push(make_pair(t->right, 0));
            }
        }
        return ans[k - 1];
    }
};