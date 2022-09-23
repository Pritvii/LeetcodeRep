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

    map<int , vector<pair<int , int >> > m;
    //map<pair<int , int >  , int > ak;
    map<int , int> idx;
    
   void solve1(TreeNode* root , int level , int right)
   {    //cout<<"ok";
       if(level % 2 == 1)
       {
           int index = idx[level];
           root->val = m[level][index].first;
           idx[level]++;
       }
       if(root->left)
       solve1(root->left , level + 1 , right -1);
       if(root->right)
       solve1(root->right , level +1 , right + 1);
    
    return;
   }
    
    void solve(TreeNode* root  , int level , int right)
    {
        if(level % 2 == 1)
        {
            m[level].push_back({root->val , right});
        }
        if(root->left)
        solve(root->left  , level +1 , right -1);
        if(root->right)
        solve(root->right , level + 1  , right  +1 );
        
        return;
        
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root  , 0 , 0 );
        for(auto el : m)
        {
            vector<pair<int , int >> temp = el.second;
            int i = 0 ; 
            int j = temp.size() -1;
            
            
            
            while(i  < j)
            {   int tempo = temp[i].first;
                temp[i].first = temp[j].first;
                temp[j].first = tempo;
                i++;
                j--;
            }
            m[el.first] = temp;
            
        }
        // for(auto el : m)
        // {
        //     int level  = el.first;
        //     vector<pair<int , int> > temp = el.second;
        //     for(auto elp : temp)
        //     {
        //         ak[{level , elp.second}] = elp.first;
        //     }
        // }
        // cout<<ak[{3,-1}];
        solve1(root , 0 , 0);
        return root;
    }
};