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
    bool ans = false;
    void solve(TreeNode* root , int ts , int cs)
    {   
        if(root == NULL )
            return;
        
        if(root->left == NULL && root->right == NULL)
        {
            cs += root->val;
            if(cs == ts)
                ans = true;
        }
        
        solve(root->left , ts  , cs + root->val);
        solve(root->right , ts  , cs + root->val);
        
        return;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        solve(root  , targetSum , 0);
        return ans;
    }
};