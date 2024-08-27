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
    
    
    ListNode* getmid(ListNode* root)
    {
        
      
        ListNode* slow=root;
        ListNode* fast=root;
        
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
                
        }
        
       
        
        return slow;
    }
    
    
    
    void display(ListNode* head)
    {
        
        ListNode* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        
        cout<<endl;
    }
    
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        
        
        if(head==NULL)
        {
            return NULL;
        }
        
        
        ListNode* mid = getmid(head);
        ListNode* right = mid->next;
        mid->next=NULL;
        
        //cout<<"value of mid is "<<mid->val<<endl;
        
        TreeNode* root = new TreeNode(mid->val);
        
        ListNode* temp = head;
        //cout<<"here head ka val is "<<head->val<<endl;
       
        
        if(temp==mid)
        {
           // cout<<"i entered here 1 \n";
            head=NULL;
            
        }else{
            
        //cout<<"i enteed here 2\n";
        while(temp->next!=mid)
        {
            temp=temp->next;
        }
            //cout<<"tem ki val hai "<<temp->val<<endl;
        temp->next=NULL;
        }
        
        //display(head);
        //display(right);
        
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(right);
        
        
        return root;
        
        
        
        
        
        
    }
};