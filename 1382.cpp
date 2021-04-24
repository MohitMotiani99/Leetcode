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
    // int ht(TreeNode* root){
    //     if(root==NULL)
    //         return 0;
    //     return 1+max(ht(root->left),ht(root->right));
    // }
    void static inorder(TreeNode* root,vector<TreeNode* >& v){
        if(root==NULL)
            return;
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
    TreeNode* bbst(vector<TreeNode* > v,int s,int e){
        if(s>e)
            return NULL;
        int mid=(s+e)/2;
        
        TreeNode* root=v[mid];
        root->left=bbst(v,s,mid-1);
        root->right=bbst(v,mid+1,e);
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
//         if(root==NULL)
//             return NULL;
//         root->left=balanceBST(root->left);
//         root->right=balanceBST(root->right);
//         int lh=ht(root->left);
//         int rh=ht(root->right);
//         if(abs(lh-rh)>1){
//             if(lh>rh){
//                 TreeNode* t=root->left;
//                 root->left=t->right;
//                 t->right=root;
//                 // t->left=balanceBST(t->left);
//                 // t->right=balanceBST(t->right);
//                 return t;
//             }
//             else{
//                 TreeNode* t=root->right;
//                 root->right=t->left;
//                 t->left=root;
//                 // t->left=balanceBST(t->left);
//                 // t->right=balanceBST(t->right);
//                 return t;
//             }
            
//         }
//         root->left=balanceBST(root->left);
//         root->right=balanceBST(root->right);
        
//         return root;
        
        vector<TreeNode* > v;
        inorder(root,v);
        
        int n=v.size();
        return bbst(v,0,n-1);
    }
};
