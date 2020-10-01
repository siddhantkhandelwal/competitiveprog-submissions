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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int n = preorder.size();
        if (!n)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> st;
        st.push(root);
        int i = 1;
        while (i < n)
        {
            TreeNode *temp = new TreeNode(preorder[i]);
            if (temp->val < st.top()->val)
            {
                st.top()->left = temp;
            }
            else
            {
                TreeNode *par = st.top();
                while (!st.empty() && temp->val > st.top()->val)
                {
                    par = st.top();
                    st.pop();
                }
                par->right = temp;
            }
            st.push(temp);
            i++;
        }
        return root;
    }
};