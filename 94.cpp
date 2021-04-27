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
    vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode* > s;
//         if(root==NULL)
//             return {};
//         //s.push(root);
//         TreeNode *curr=root;
//         vector<int> ans;
//         while(curr || !s.empty()){
            
//             while(curr){
//                 s.push(curr);
//                 curr=curr->left;
//             }
//             curr=s.top();
//             s.pop();
//             ans.push_back(curr->val);
//             curr=curr->right;
//         }
//         return ans;
        
        vector<int> ans;
        TreeNode * curr=root;
        while(curr){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode *pre=curr->left;
                while(pre->right && pre->right!=curr){
                    pre=pre->right;
                }
                if(!pre->right){
                    pre->right=curr;
                    curr=curr->left;
                }
                else{
                    ans.push_back(curr->val);
                    pre->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};
