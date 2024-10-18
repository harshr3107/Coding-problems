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
    
    
    
   
    
    int getallpossible(TreeNode* root,map<TreeNode*,int>& dp)
    {
        
        if(root==NULL)
        {
            return 0;
        }
        
        
        if(dp.count(root))
        {
            return dp[root];
        }
        
        
        int leftpick = 0;
        
          if(root->left!=NULL)
          {
           leftpick = getallpossible(root->left->left,dp)+getallpossible(root->left->right,dp);
          }
           
         int  leftnotpick = getallpossible(root->left,dp);
          
        int rightpick = 0;
        if(root->right!=NULL)
        {
            rightpick = getallpossible(root->right->right,dp)+getallpossible(root->right->left,dp);
        }
        
        int rightnotpick = getallpossible(root->right,dp);
        
        //cout<<leftpick<<" "<<leftnotpick<<" "<<rightpick<<" "<<rightnotpick<<" at the root "<<root->val<<endl;
        
        dp[root]=max(leftpick+rightpick+root->val,leftnotpick+rightnotpick);
        
        return max(leftpick+rightpick+root->val,leftnotpick+rightnotpick);
        
        
        
        
        
        
        
        
        
    }
    
    
    
    
    
    
    
    
    
    int rob(TreeNode* root) {
        
        map<TreeNode*,int> dp;
        vector<int> vec;
        
        return getallpossible(root,dp);
        
        
        
        
        
       
        
        
        //vector<int> dp(vec.size(),-1);
        //int h = getmax(vec,0,dp);
        
        
        
        
        
        
    }
};

/*
class Solution {
public:
    
    int getallpossible(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        // Picking the current node
        int leftpick = 0, rightpick = 0;
        if (root->left != NULL) {
            leftpick = getallpossible(root->left->left) + getallpossible(root->left->right);
        }
        if (root->right != NULL) {
            rightpick = getallpossible(root->right->left) + getallpossible(root->right->right);
        }
        
        // Adding the current node's value when picking
        int pick = root->val + leftpick + rightpick;
        
        // Not picking the current node, we take the best values from the left and right children
        int leftnotpick = getallpossible(root->left);
        int rightnotpick = getallpossible(root->right);
        
        // The maximum value we can get at this node is either by picking or not picking it
        return max(pick, leftnotpick + rightnotpick);
    }
    
    int rob(TreeNode* root) {
        // Start by calling the helper function
        return getallpossible(root);
    }
};*/
