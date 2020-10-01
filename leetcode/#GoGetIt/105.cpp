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
private:
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &rootidx, int left, int right)
    {
        if (left > right)
        {
            return NULL;
        }
        int pivot = left;
        while (inorder[pivot] != preorder[rootidx])
        {
            pivot++;
        }
        rootidx++;
        TreeNode *newnode = new TreeNode(inorder[pivot]);
        newnode->left = helper(preorder, inorder, rootidx, left, pivot - 1);
        newnode->right = helper(preorder, inorder, rootidx, pivot + 1, right);
        return newnode;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int rootidx = 0;
        return helper(preorder, inorder, rootidx, 0, inorder.size() - 1);
    }
};