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
class Solution {
public:
    vector<int> nodes;
    void solve(TreeNode* root)
    {   if(root == NULL)
            return;
        nodes.push_back(root->val);
        if(root->left)
            solve(root->left);
        if(root->right)
            solve(root->right);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        solve(root);
        sort(nodes.begin() , nodes.end());
        int i = 0 ;
        int j = nodes.size() - 1;
        while(i<j)
        {
            if(nodes[i] + nodes[j] == k)
                return true;
            else if(nodes[i] + nodes[j] > k)
                j--;
            else
                i++;
        }
        return false;
    }
};