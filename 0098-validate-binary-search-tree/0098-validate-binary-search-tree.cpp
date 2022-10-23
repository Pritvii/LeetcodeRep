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
    vector<int> arr;
    void ino(TreeNode* root){
        if(root){
            ino(root->left);
            arr.push_back(root->val);
            ino(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        //inorder must be sorted
        ino(root);
        for(int i = 0 ; i < arr.size() - 1 ; i++){
            if(arr[i] >= arr[i+1]){
                return false;
            }
        }
        return true;
    }
};