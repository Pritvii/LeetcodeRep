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
    map<int  ,vector<int> > m;
    void solve(TreeNode* root  , int level)
    {
        if(root == NULL)
        {
            return;
        }
        
        m[level].push_back(root->val);
        solve(root->left , level  + 1);
        solve(root->right , level  +1);
        
        return;
        
        
    }
    int deepestLeavesSum(TreeNode* root) {
        solve(root ,  0 );
        int n = m.size() - 1 ;
        int sum = 0 ;
        for(int el : m[n])
        {
            sum += el;
        }
        return sum;
    }
};