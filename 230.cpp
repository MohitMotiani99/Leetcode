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
    // void inorder(TreeNode* root,vector<int>& v){
    //     if(root==NULL)
    //         return;
    //     inorder(root->left,v);
    //     v.push_back(root->val);
    //     inorder(root->right,v);
    // }
    int io(TreeNode* root,int k){
        if(root==NULL)
            return -1;
        int c=0;
        TreeNode *curr=root;
        stack<TreeNode* > s;
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            //v.push_back(curr->val);
            c++;
            if(c==k)
                return curr->val;
            curr=curr->right;
        }
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        return io(root,k);
        //return v[k-1];
        
        
    }
};
