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
    int findBottomLeftValue(TreeNode* root) {
        
        
        if(root==NULL)
        {
            return -1;
        }
        
        queue<TreeNode*> q;
        vector<int> v;
        
        q.push(root);
        q.push(NULL);
        
        int ans;
        
        
        
        while(!q.empty())
        {
            
            TreeNode* temp = q.front();
            q.pop();
            
           
            if(temp==NULL)
            {
                ans=v[0];
                
                v.clear();
                
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
                
                
            }else{
                v.push_back(temp->val);
                
                
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
            }
            
            
            
            
            
            
            
        }
        
        
        return ans;
        
        
    }
};