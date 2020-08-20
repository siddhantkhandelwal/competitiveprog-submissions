/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    unordered_map<TreeNode *, TreeNode *> par;
    unordered_set<TreeNode *> visited;
    void dfs(TreeNode *root, TreeNode *target)
    {
        if (root == NULL || root == target)
        {
            return;
        }
        if (root->left)
        {
            par[root->left] = root;
            dfs(root->left, target);
        }
        if (root->right)
        {
            par[root->right] = root;
            dfs(root->right, target);
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        if (!root)
        {
            return {};
        }
        vector<int> res;
        dfs(root, target);
        queue<TreeNode *> q;
        q.push(target);
        while (!q.empty())
        {
            int l = q.size();
            while (l--)
            {
                TreeNode *temp = q.front();
                q.pop();
                visited.insert(temp);
                if (K == 0)
                {
                    res.push_back(temp->val);
                }
                if (temp->left && !visited.count(temp->left))
                {
                    q.push(temp->left);
                }
                if (temp->right && !visited.count(temp->right))
                {
                    q.push(temp->right);
                }
                if (par[temp] && !visited.count(par[temp]))
                {
                    q.push(par[temp]);
                }
            }
            K--;
        }
        return res;
    }
};