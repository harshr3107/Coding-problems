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
    
    
    TreeNode* getparentmaping(TreeNode* root,map<TreeNode*,TreeNode*>& mp,int target)
    {
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        TreeNode* ans;
        
        
       // mp[root]=NULL;
        
        while(!q.empty())
        {
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp==NULL)
            {
                
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
                
            }else{
                
                if(temp->val==target)
                {
                    ans=temp;
                }
                
              
                if(temp->left!=NULL)
                {
                    
                    
                    mp[temp->left]=temp;
                    q.push(temp->left);
                }
                
                if(temp->right!=NULL)
                {
                    mp[temp->right]=temp;
                    q.push(temp->right);
                }
                
                
            }
            
            
        }
        
        
        
        return ans;
        
            
    }
    
    
    int gettime(TreeNode* targetnode,map<TreeNode*,TreeNode*> mp)
    {
        map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        
        
        int sec=0;
        
        q.push(targetnode);
        q.push(NULL);
        visited[targetnode]=true;
        int a=0;
        
        while(!q.empty())
        {
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp==NULL)
            {

                if(a!=0)
                {
                    sec++;
                }
                
                a=0;
            
                if(!q.empty())
                {
                    q.push(NULL);
                }
              
                
            
            
            }else{
            
            
            if(temp->left!=NULL && visited[temp->left]!=true)
            {
                a++;
                q.push(temp->left);
                visited[temp->left]=true;
                
            }
            if(temp->right!=NULL && visited[temp->right]!=true)
            {
                a++;
                q.push(temp->right);
                visited[temp->right]=true;
            }
            
            if(mp[temp]!=NULL && visited[mp[temp]]!=true)
            {
                a++;
                q.push(mp[temp]);
                visited[mp[temp]]=true;
            }
            
           
            }
        }
        
        return sec;
        
    }
    
    
    
    
    
    
    int amountOfTime(TreeNode* root, int start) {
        
        
        map<TreeNode*,TreeNode*> mp;
        
        TreeNode* targetnode = getparentmaping(root,mp,start);
        
        cout<<"the target node is "<<targetnode->val<<endl;
        
        /*for(auto it: mp)
        {
            cout<<it.first->val<<" "<<it.second->val<<endl;
        }*/
        
        
        
        
        int sec = gettime(targetnode,mp);
        
        
        return sec;
        
        
        
    }
};