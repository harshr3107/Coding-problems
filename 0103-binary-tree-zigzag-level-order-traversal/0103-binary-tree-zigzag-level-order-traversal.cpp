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
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        
        
        
        
        vector<vector<int>> ans;
        
        if(root==NULL)
        {
            return ans;
        }
        
        
        vector<int> v;
        int a=0;
        
        while(!q.empty())
        {
            
            TreeNode* p = q.front();
            q.pop();
            
            if(p==NULL)
            {
                //cout<<endl;
                if((a&1)==1)
                {
                    reverse(v.begin(),v.end());
                }
                
                ans.push_back(v);
                v.clear();
                
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
                a++;
                
                
            }else{
                
                //cout<<p->val<<" ";
                v.push_back(p->val);
                
                if(p->left!=NULL)
                {
                    q.push(p->left);
                }
                
                if(p->right!=NULL)
                {
                    q.push(p->right);
                }
                
                
            }
            
            
            
        }
        
        return ans;
        
    }
};