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
        
        
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<vector<int>> ans;
        vector<int> v;
        
        if(root==NULL)
        {
            
            return ans;
        }
        
        
        
        while(!q.empty())
        {
            TreeNode* p = q.front();
            q.pop();
            
            if(p==NULL)
            {
                cout<<endl;
                ans.push_back(v);
                v.clear();
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
                
            }else{
            
            
            
            cout<<p->val<<" ";
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