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
    vector<string> ans;
    void solve(TreeNode* root , int sum  , int curr_sum , string osf)
    {   if(root == NULL)
        {
            return;
        }
        if(root->left  == NULL && root->right == NULL)
        {
            curr_sum += root->val;
            if(curr_sum == sum)
            {   osf += to_string(root->val) + " ";
                ans.push_back(osf);
            }
            return;
        }
        
        if(root->left)
        solve(root->left , sum , curr_sum + root->val , osf + to_string(root->val) + " ");
        if(root->right)
        solve(root->right , sum , curr_sum + root->val , osf + to_string(root->val) + " ");
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root , targetSum , 0 , "");
        vector<vector<int>> answ;
        for(string el : ans)
        {
            vector<int> temp;
            for(int i = 0 ; i < el.length() ; i ++)
            {
                string tempo = "";
                
                while(el[i]  != ' ' )
                {
                    tempo += el[i];
                    i++;
                }
            
                int num = stoi(tempo);
                temp.push_back(num);
            }
            answ.push_back(temp);
        }
        return answ;
    }
};