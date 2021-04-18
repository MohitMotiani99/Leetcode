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
    TreeNode* addRow(TreeNode* root, int val, int depth,int side){
        if(depth==1){
            
            TreeNode *t=new TreeNode(val);
            if(root==NULL)
                return t;
            if(side==0)
                t->left=root;
            else
                t->right=root;
            
            return t;
        }
        if(root==NULL)
            return NULL;
        root->left=addRow(root->left,val,depth-1,0);
        root->right=addRow(root->right,val,depth-1,1);
        
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL){
            TreeNode *t=new TreeNode(val);
            return t;
        }
        return addRow(root,val,depth,0);
    }
};
