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
    
    TreeNode* findinprec(TreeNode* root)
    {
        TreeNode* temp = root;
        temp=temp->right;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        
        return temp;
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
        {
            return root;
        }
            
        
        if(root->val==key)
        {
           // cout<<"i entered here for "<<key<<endl;
            
            
            //NO child
            if(root->left==NULL && root->right==NULL)
            {
                
                root=root->left;
                return root;
                
                //single child
            }else if(root->left==NULL)
            {
                TreeNode* temp =root->right;
                
               
                
                return temp;
                
                
            }else if(root->right==NULL)
            {
                TreeNode* temp =root->left;
                
                
                
                return temp;
                
            }else{
                //Both child
                
               // cout<<"i have 2 child\n";
                
                TreeNode* prec = findinprec(root);
                root->val= prec->val;
                root->right = deleteNode(root->right,prec->val);
                return root;
                
                
                
                
            }
            
            
            
            
            
            
            
        }else if(root->val>key)
        {
            root->left = deleteNode(root->left,key);
            return root;
        }else{
            
            
            root->right = deleteNode(root->right,key);
            return root;
        }
        
       return root;
        
        
    }
};