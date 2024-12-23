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
    
    
    
    int getswap(vector<int>& v)
    {
        
        
        
        
        vector<pair<int,int>> v1;
        
        
        for(int i=0;i<v.size();i++)
        {
          
           v1.push_back(make_pair(v[i],i));
        }
        
        cout<<endl;
        sort(v1.begin(),v1.end());
        
        int swap=0;
        
        
        for(int i=0;i<v1.size();i++)
        {
            
            if(v1[i].second==i)
            {
                continue;
            }else{
                
                swap++;
                int j=i+1;
                while(v1[j].second!=i)
                {
                    j++;
                }
                
                pair<int,int> temp = v1[j];
                v1[j]=v1[i];
                v1[i]=temp;
                
                
                
                
            }
        }
        
        
        return swap;
        
        
        
        
    }
    
    
    
    
    
    
    
    
    
    
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> v;
        
        int ans=0;
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp==NULL)
            {
                
                ans+=getswap(v);
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
        
        
        
        
        return ans;
        
    }
};