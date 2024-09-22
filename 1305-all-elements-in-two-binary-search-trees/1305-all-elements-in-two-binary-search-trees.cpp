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
    
    void preorder(TreeNode*& root,priority_queue<int,vector<int>,greater<int>>& s)
    {
        if(root!=NULL)
        {
            preorder(root->left,s);
            preorder(root->right,s);
            s.push(root->val);
            
        }
    }
    
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        //multiset<int> s;
        priority_queue<int,vector<int>,greater<int>> s;
        preorder(root1,s);
        preorder(root2,s);
        
       vector<int> v;
        
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        
        return v;
         
        
    }
};