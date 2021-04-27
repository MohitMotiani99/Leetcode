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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int> > ans;
        queue<TreeNode* > q;
        q.push(root);
        TreeNode* br=new TreeNode(1002);
        q.push(br);
        vector<int> out;
        while(!q.empty()){
            TreeNode* p=q.front();
            q.pop();
            
            if(p->val!=1002){
                out.push_back(p->val);
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
            }
            else{
                if(q.size()!=0){
                    q.push(p);
                    ans.push_back(out);
                    out.clear();
                }
                else if(out.size()!=0){
                    ans.push_back(out);
                }
            }
        }
        return ans;
    }
};
