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
    map<int , vector<pair<int , int > > > m;
    void solve(TreeNode* root , int level  , int right)
    {   if(root == NULL)
        return;
        m[level].push_back({root->val , right});
        solve(root -> right , level + 1 , right + 1);
        solve(root -> left , level + 1 , right - 1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root , 0 , 0);
        cout<<m.size()<<endl;
        vector<int> ans;
        for(int i = 0 ; i < m.size() ; i ++)
        {
              vector<pair<int  , int>> temp =  m[i];
              int num = temp[0].first;
              ans.push_back(num);  
                
            
        }
        return ans;
    }
};