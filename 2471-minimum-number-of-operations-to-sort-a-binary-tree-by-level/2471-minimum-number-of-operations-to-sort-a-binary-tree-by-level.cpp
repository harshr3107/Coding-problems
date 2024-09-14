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
    
    
    
    
    
    int getans(vector<int> v)
    {
        
        vector<pair<int,int>> v1;
        
        for(int i=0;i<v.size();i++)
        {
            v1.push_back(make_pair(v[i],i));
        }
        
        
        sort(v1.begin(),v1.end());
        
        
        int i=0;
        int a=0;
        
        while(i<v1.size())
        {
            
            if(v1[i].second==i)
            {
                i++;
            }else{
                
                int j=i+1;
                while(v1[j].second!=i)
                {
                    j++;
                }
                
                swap(v1[j],v1[i]);
                a++;
                
                
                
            }
            
            
        }
        
        
       
        return a;
        
        
        
    }
    
    
    int levelorder(TreeNode* root)
    {
        if(root==NULL || (root->left==NULL && root->right==NULL))
        {
            return 0;
        }
        
        
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
                
                if(v.size()!=1)
                {
                    ans+=getans(v);
                    //cout<<"current val of ans is "<<ans<<endl;
                }
                
                
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
    
    
    
    
    
    
    
    
    
    int minimumOperations(TreeNode* root) {
        
        return levelorder(root);
        
    }
};