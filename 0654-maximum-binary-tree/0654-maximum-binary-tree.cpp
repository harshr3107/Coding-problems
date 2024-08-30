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
    TreeNode* gettree(vector<int> nums,int start,int end)
    {
        if(end<start)
        {
            return NULL;
        }
        
        if(end==start)
        {
            TreeNode* n =  new TreeNode(nums[start]);
            return n;
        }
        
        //cout<<"start is "<<start<<" end is "<<end<<endl;
        
        vector<int>:: iterator maxelement = max_element(nums.begin()+start,nums.begin()+end+1);
        TreeNode* root = new TreeNode(*maxelement);
        //cout<<"maxelement is "<<*maxelement<<endl;
        
        root->left = gettree(nums,start,maxelement-nums.begin()-1);
        root->right = gettree(nums,maxelement-nums.begin()+1,end);
        
        return root;
        
        
    }
    
    
    
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       
        int i=0;
        int j=nums.size()-1;
        
        TreeNode* root = gettree(nums,i,j);
        
        
        return root;
        
       
        
    }
};