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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        if (!n)
        {
            return NULL;
        }
        int mid = (n & 1) ? (n - 1) / 2 : n / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        vector<int> lt;
        vector<int> rt;
        for (int i = 0; i < mid; i++)
        {
            lt.push_back(nums[i]);
        }
        for (int i = mid + 1; i < n; i++)
        {
            rt.push_back(nums[i]);
        }
        a
            root->left = sortedArrayToBST(lt);
        root->right = sortedArrayToBST(rt);
        return root;
    }
};