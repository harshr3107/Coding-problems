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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        if(root==NULL)
        {
            return -1;
        }
        
        queue<TreeNode*> q;
        priority_queue<long long> maxheap;
        
        q.push(root);
        q.push(NULL);
        
        vector<long long> v; 
        
        
        
        while(!q.empty())
        {
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp==NULL)
            {
                
                long long sum = accumulate(v.begin(),v.end(),0LL);
                //cout<<"current level sum is "<<sum<<endl;
                maxheap.push(sum);
                v.clear();
                
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
                
                
            }else{
                
                v.push_back(temp->val);
                
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                
                
                
            }
            
            
        }
        
       
        
        if(maxheap.size()<k)
        {
            return -1;
        }
        
        int i=1;
        
        while(i<k)
        {
            maxheap.pop();
            i++;
        }
        
        
        return maxheap.top();
        
        
        
        
        
        
    }
};