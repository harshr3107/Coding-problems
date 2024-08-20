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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        vector<vector<int>> ans;
        
        if(root==NULL)
        {
            return ans;
        }
        
        
        stack<vector<int>> st;
      
         q.push(root);
         q.push(NULL);
        
        vector<int> v;
        
        while(!q.empty())
        {
            
            TreeNode* p = q.front();
            q.pop();
            
            if(p!=NULL)
            {
                v.push_back(p->val);
                cout<<p->val<<" ";
                
                
                 if(p->left!=NULL)
                {
                    q.push(p->left);
                }
                
                if(p->right!=NULL)
                {
                    q.push(p->right);
                }
                
               
            }else{
                
                cout<<endl;
                //ans.push_back(v);
                st.push(v);
                v.clear();
                
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
                
                
                
                
            }
            
            
            
        }
        
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        
        return ans;
        
        
        
    }
};