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
    vector<double> averageOfLevels(TreeNode* root) {
        double sum=0.0,c=0.0;
        vector<double> ans;
        queue<TreeNode* > q;
        q.push(root);
        TreeNode *br=new TreeNode(0);
        q.push(br);
        while(!q.empty()){
            TreeNode* p=q.front();
            q.pop();
            if(p==br){
                ans.push_back(sum/c);
                sum=0;
                c=0;
                if(!q.empty())
                q.push(p);
            }
            else{
                sum+=(p->val);
                c++;
                
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
            }
        }
        return ans;
    }
};
