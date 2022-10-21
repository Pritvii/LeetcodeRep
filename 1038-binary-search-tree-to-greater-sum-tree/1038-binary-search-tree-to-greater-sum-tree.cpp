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
    vector<int> data;
    map<int , int> x;
    void solve_fun(TreeNode* root){
        if(root == NULL)return;
        
            cout<<root->val<<" "<<x[root->val]<<endl;
            root->val = x[root->val];
            solve_fun(root->left);
            solve_fun(root->right);
            
        
    }
    void solve(TreeNode* root){
        if(root == NULL)return;
        
        data.push_back(root->val);
        solve(root->right);
        solve(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
     solve(root);
     sort(data.begin(),data.end());
     for(int i = 0 ; i < data.size() ; i ++)
     {   int sum = 0 ;
         for(int j = 0 ;  j < data.size() ;  j++)
         {
             if(data[j] > data[i]){
                 sum+=data[j];
             }
         }
      x[data[i]] = sum + data[i];
     }
    solve_fun(root);
        return root;
    }
};