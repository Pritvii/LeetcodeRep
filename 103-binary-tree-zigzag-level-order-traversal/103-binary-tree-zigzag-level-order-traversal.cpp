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
    map<int , vector<int>> m;
    void solve(TreeNode* root , int level)
    {
        if(root == NULL)
            return;
        m[level].push_back(root->val);
        if(root->left)
            solve(root->left , level + 1);
        if(root->right)
            solve(root->right , level + 1);
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        solve(root  , 0);
        vector<vector<int>> ans;
        int i = 0 ;
        for(auto el : m)
        {   if(i % 2 == 0 ){
            vector<int> x = el.second;
            ans.push_back(x);
            }
            else
            {
                vector<int> temp = el.second;
                reverse(temp.begin() , temp.end());
                ans.push_back(temp);
            }
         i++;
        }
        return ans;
    }
};