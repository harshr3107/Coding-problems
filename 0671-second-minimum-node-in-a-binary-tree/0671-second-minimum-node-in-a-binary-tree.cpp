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
    
    set<int> s;
    
  
    
    void getsecondmin(TreeNode* root)
    {
        
        if(root==NULL)
        {
            return;
        }
        
      
        
        getsecondmin(root->left);
        getsecondmin(root->right);
        
        
      s.insert(root->val);
        
        
        
    }
    
    
    
    
    
    
    
    
    int findSecondMinimumValue(TreeNode* root) {
        
        
        
        getsecondmin(root);
        
        auto it = s.rbegin();
        auto it2 = s.begin();
        
        
        
       
        
        
        if(s.size()<2)
        {
            return -1;
        }
        
        
        it2++;
        
        
        return *(it2);
        
        
    }
};