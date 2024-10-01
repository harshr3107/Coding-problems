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
    
    int getsum(TreeNode* root)
    {
        
        if(root==NULL)
        {
            return 0;
        }
        
        return root->val+getsum(root->left)+getsum(root->right);
        
    }
    
    
    
    void inorder(TreeNode* root,int& sum)
    {
        if(root!=NULL)
        {
            inorder(root->left,sum);
            //cout<<root->val<<" ";
            int h = root->val;
            //cout<<"current sum is "<<sum<<endl;
            root->val=sum;
            sum=sum-h;
            inorder(root->right,sum);
        }
        
    }
    
    
    
    
    TreeNode* bstToGst(TreeNode* root) {
        
        int sum = getsum(root);
        
        int csum=0;
        
        inorder(root,sum);
        
        return root;
        
    }
};