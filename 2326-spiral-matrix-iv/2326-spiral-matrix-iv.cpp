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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> ans;
        
        for(int i=0;i<m;i++)
        {
            vector<int> v(n,-1);
            ans.push_back(v);
        }
        
        
        
        
        
        int row_start=0;
        int row_end=m-1;
        int col_start=0;
        int col_end=n-1;
        
        
        while(head!=NULL && row_start<=row_end && col_start<=col_end )
        {
            
            for(int i=col_start;i<=col_end;i++)
            {
                if(head!=NULL)
                {
                ans[row_start][i]=head->val;
                head=head->next;
                }
                
            }
            
            row_start++;
            
            for(int i=row_start;i<=row_end;i++)
            {
                if(head!=NULL)
                {
                 ans[i][col_end]=head->val;
                 head=head->next;
                }
            }
            
            
            col_end--;
            
            for(int i=col_end;i>=col_start;i--)
            {
                if(head!=NULL)
                {
                ans[row_end][i]=head->val;
                head=head->next;
                }
            }
            
            row_end--;
            
            for(int i=row_end;i>=row_start;i--)
            {
                
                if(head!=NULL)
                {
                 ans[i][col_start]=head->val;
                 head=head->next;
                }
                
            }
            
            col_start++;
            
        }
        
        
        return ans;
        
        
        
        
        
        
    }
};