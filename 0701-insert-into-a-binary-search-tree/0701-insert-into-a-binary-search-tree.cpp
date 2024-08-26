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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        
        TreeNode* n = new TreeNode(val);
        
         if(root==NULL)
         {
             return n;
         }
        
        TreeNode* prev = root;
        TreeNode* temp = root;
        
        while(temp!=NULL)
        {
            
            prev=temp;
            
            if(temp->val>val)
            {
                temp=temp->left;
            }else{
                temp=temp->right;
            }
        }
        
        if(prev->val>val)
        {
            prev->left=n;
        }else{
            prev->right=n;
        }
        
        
        return root;
        
    }
};