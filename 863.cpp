/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
        
        map<TreeNode*,TreeNode*> m;
        set<TreeNode*> vis;
//     pair<int,int> static rootdis(TreeNode* root,TreeNode *target){
//         if(root==NULL)
//             return {-1,0};
//         if(root==target)
//             return {0,0};
//         pair<int,int> dist=rootdis(root->left,target);
//         if(dist.first>=0)
//             return {dist.first+1,0};
//         dist=rootdis(root->right,target);
//         if(dist.first>=0)
//             return {dist.first+1,1};
//         return {-1,0};
//     }
//     void static nodes(TreeNode* root,vector<int>& v,int k){
//         if(root==NULL)
//             return;
//         queue<pair<TreeNode*,int> > q;
//         q.push({root,0});
//         while(!q.empty()){
//             pair<TreeNode*,int> p=q.front();
//             q.pop();
            
//             if(p.second>k)
//                 break;
//             if(p.second==k)
//                 v.push_back(p.first->val);
//             else{
//                 if(p.first->left)q.push({p.first->left,p.second+1});
//                 if(p.first->right)q.push({p.first->right,p.second+1});
//             }
//         }
//     }
    
    void findp(TreeNode* root){
        if(!root)
            return;
        if(root->left){
            m[root->left]=root;
            findp(root->left);
        }
        if(root->right){
            m[root->right]=root;
            findp(root->right);
        }
    }
    void dfs(TreeNode* node,int k,vector<int>& ans){
        if(vis.find(node)!=vis.end())
            return;
        vis.insert(node);
        if(k==0){
            ans.push_back(node->val);
            return;
        }
        if(node->left)
            dfs(node->left,k-1,ans);
        if(node->right)
            dfs(node->right,k-1,ans);
        TreeNode *p=m[node];
        if(p)
            dfs(p,k-1,ans);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
//         vector<int> ans;
        
//         nodes(target,ans,K);
//         if(K==0 || root==target)
//             return ans;
//         pair<int,int> d=rootdis(root,target);
//         cout<<d.first<<" "<<d.second<<endl;
//         if(K>d.first){
//             if(d.second==0)
//             nodes(root->right,ans,K-d.first-1);
//             else
//             nodes(root->left,ans,K-d.first-1);
//         }
//         else if(d.first==K)
//             ans.push_back(root->val);
//         else{
//             if(d.second==0)
//             nodes(root->left,ans,d.first-1-K);
//             else
//             nodes(root->right,ans,d.first-1-K);
//         }
            
//         return ans;
        
        vector<int> ans;
        if(!root)
            return {};
        findp(root);
        dfs(target,K,ans);
        return ans;
    }
};
