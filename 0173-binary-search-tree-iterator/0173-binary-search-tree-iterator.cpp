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
class BSTIterator {
public:
    
    vector<int> inorder;
    int curr;

    
    
    
    
    
    BSTIterator(TreeNode* root) {
        
        inorder.push_back(-1);
        inordertra(root);
        curr=0;
        
        
    }
    
    
    void inordertra(TreeNode* root)
    {
        
        if(root!=NULL)
        {
            inordertra(root->left);
            inorder.push_back(root->val);
            inordertra(root->right);
            
        }
        
        
    }
    
    
    
    int next() {
        
        curr++;
        return inorder[curr];
        
    }
    
    bool hasNext() {
        
        if(curr==inorder.size()-1)
        {
            return false;
        }
        
        return true;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */