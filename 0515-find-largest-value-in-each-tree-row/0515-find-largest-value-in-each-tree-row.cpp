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
    vector<int> largestValues(TreeNode* root) {
        
           vector<int> ans;
        
        if(root==NULL)
        {
            return ans;
        }
        
        
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        set<int> s;
        
     
        
        while(!q.empty())
        {
            
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp==NULL)
            {
                int a = *(s.rbegin());
                s.clear();
                ans.push_back(a);
                
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
                
                
                
            }else{
                
                s.insert(temp->val);
                
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