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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int> > ans;
        queue<TreeNode* > q;
        q.push(root);
        TreeNode* br=new TreeNode(1002);
        q.push(br);
        vector<int> out;
        int c=0;
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
                    if(c%2==0)
                    ans.push_back(out);
                    else{
                        reverse(out.begin(),out.end());
                        ans.push_back(out);
                    }
                    c++;
                    out.clear();
                }
                else if(out.size()!=0){
                    if(c%2==0)
                    ans.push_back(out);
                    else{
                        reverse(out.begin(),out.end());
                        ans.push_back(out);
                    }
                    c++;
                }
            }
        }
        return ans;
   
    }
};
