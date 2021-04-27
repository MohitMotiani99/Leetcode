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
    
    TreeNode* bt(vector<int>& preorder, vector<int>& inorder,int ps,int pe,int is,int ie,int s){
        if(ps>=s ||is>=s)
            return NULL;
        if(ps>pe || is>ie || is<0 || ps<0 || pe>=s || ie>=s)
            return NULL;
        int r=preorder[ps];
        int i;
        for(i=is;i<=ie;i++){
            if(inorder[i]==r)
                break;
        }
        TreeNode *root=new TreeNode(r);
        root->left=bt(preorder,inorder,ps+1,ps+i-is,is,i-1,s);
        root->right=bt(preorder,inorder,ps+i-is+1,pe,i+1,ie,s);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return NULL;
        //TreeNode* root=new TreeNode(preorder[0]);
        return bt(preorder,inorder,0,preorder.size()-1,0,preorder.size()-1,preorder.size());
    }
};
