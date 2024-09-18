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


void modifytree(TreeNode*& root)
    {
            if(root==NULL)
            {
                return;
            }
        
       
        if(root->left!=NULL)
        {
            root->left->val = 2*root->val+1;
        }
        
        if(root->right!=NULL)
        {
            root->right->val = 2*root->val+2;
        }
        
        
        modifytree(root->left);
        modifytree(root->right);
          
        
        
        
        
    }




class FindElements {
public:
    
    TreeNode* r;
    
    FindElements(TreeNode* root) {
        
        
       root->val=0;
       modifytree(root);
       r=root;
       //cout<<"i have been initialized\n";
      preorder(root);
        
    }
    
    
    void preorder(TreeNode* root)
    {
        if(root!=NULL)
        {
           
            preorder(root->left);
             cout<<root->val<<" ";
            preorder(root->right);
            
        }
        
    }
    
    
    
    
    
    
    bool getans(TreeNode* root,int target)
    {
        if(root==NULL)
        {
            return false;
        }
        
        if(root->val==target)
        {
            return true;
        }
        
        if(getans(root->left,target)==true)
        {
            return true;
        }
        
        if(getans(root->right,target)==true)
        {
            return true;
        }
        
        return false;
        
        
        
    }
        
        
        
    bool find(int target) {
        
       //preorder(r);
       
       //preorder(root);
       //cout<<endl;
        
       return getans(r,target);
        //return false;
       
        
       
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */