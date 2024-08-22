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
    vector<int> rightSideView(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> v;
        vector<int> ans;
        
        if(root==NULL)
        {
            return ans;
        }
        
        while(!q.empty())
        {
            TreeNode*  temp = q.front();
            q.pop();
            
            if(temp==NULL)
            {
                ans.push_back(v[v.size()-1]);
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