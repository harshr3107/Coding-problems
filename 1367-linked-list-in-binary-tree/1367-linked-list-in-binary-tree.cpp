/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    bool checkpath(ListNode* head,TreeNode* root)
    {
        
        if(root==NULL)
        {
            return false;
        }
        
       
        if(head->val!=root->val)
        {
            return false;
        }
        
        if(head->next==NULL)
        {
            return true;
        }
        
        
        bool left = checkpath(head->next,root->left);
        bool right = checkpath(head->next,root->right);
        
        
        return left||right;
        
        
        
        
        
        
    }
    
    
    
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if(root==NULL)
        {
            return false;
        }
        
        if(checkpath(head,root)==true)
        {
            return true;
        }
        
        
        return isSubPath(head,root->left) || isSubPath(head,root->right);
        
        
        
    }
};