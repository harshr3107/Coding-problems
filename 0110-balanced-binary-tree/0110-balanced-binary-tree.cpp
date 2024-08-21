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
    
    int getheight(TreeNode* root,bool& ans)
    {
       
        if(root==NULL)
        {
            return 0;
        }
        
        int left = getheight(root->left,ans);
        int right = getheight(root->right,ans);
        if(abs(right-left)>1)
        {
            ans=false;
        }
        
        return 1+max(left,right);
        
    }
    
    
    
    
    bool isBalanced(TreeNode* root) {
        
           bool ans=true;
           getheight(root,ans);
        
          return ans;
    }
};