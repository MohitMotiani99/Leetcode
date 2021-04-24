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
    int static ht(TreeNode* root,unordered_map<TreeNode*,int>& m){
        if(root==NULL)
            return 0;
        if(m.find(root)!=m.end())
            return m[root];
        return m[root]=1+max(ht(root->left,m),ht(root->right,m));
    }
    bool static bal(TreeNode* root,unordered_map<TreeNode*,int>& m){
        if(root==NULL)
            return true;
        int lh=m[root->left];
        int rh=m[root->right];
        
        if(abs(lh-rh)>1)
            return false;
        
        return bal(root->left,m) && bal(root->right,m);
    }
    bool isBalanced(TreeNode* root) {
        
        unordered_map<TreeNode*,int> m;
        ht(root,m);
        
        return bal(root,m);
        
    }
};
