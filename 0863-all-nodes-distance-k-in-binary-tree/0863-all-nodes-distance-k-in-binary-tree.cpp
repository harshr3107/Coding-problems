/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    
    void getparentmapping(TreeNode* root,map<int,TreeNode*>& mp)
    {
        
        queue<TreeNode*> q;
        q.push(root);
       
        
        //cout<<"i entered here\n";
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            
           // cout<<"i am here for "<<temp->val<<endl;
            
             
            if(temp->left!=NULL)
            {
                mp[temp->left->val]=temp;
                
                q.push(temp->left);
                
            }
            
            if(temp->right!=NULL)
            {
                mp[temp->right->val]=temp;
                q.push(temp->right);
            }
            
            
        }
        
        //cout<<"i came outside\n";
        
    }
    
    
    
    void getallans(TreeNode* target, map<int,TreeNode*>& parentnode,int k,vector<int>& v)
    {
        
        int sec=0;
        
        queue<pair<TreeNode*,int>> q;
        
        q.push(make_pair(target,0));
        
        map<TreeNode*,bool> visited;
        
        visited[target]=true;
        
        while(!q.empty())
        {
           pair<TreeNode*,int> temp = q.front();
           q.pop();
           int time = temp.second;
           TreeNode* cnode = temp.first;
            
           // cout<<"the node "<<cnode->val<<" time "<<time<<endl;
            
           
            if(time==k)
            {
                //cout<<"i am here for "<<cnode->val<<endl;
                v.push_back(cnode->val);
                continue;
            }
            
            
            if(cnode->left!=NULL && visited[cnode->left]!=true && time+1<=k)
            {
                 q.push(make_pair(cnode->left,time+1));  
                 visited[cnode->left]=true;
                     
            }
            
            if(cnode->right!=NULL && visited[cnode->right]!=true && time+1<=k)
            {
                q.push(make_pair(cnode->right,time+1));   
                visited[cnode->right]=true;
            }
            
            if(parentnode.count(cnode->val) && visited[parentnode[cnode->val]]!=true && time+1<=k)
            {
                q.push(make_pair(parentnode[cnode->val],time+1));   
                visited[parentnode[cnode->val]]=true;
                
            }
            
            
            
            
            
        }
        
        
    }
    
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        map<int,TreeNode*> parentnode;
        
        getparentmapping(root,parentnode);
        vector<int> v;
        
        getallans(target,parentnode,k,v);
        
        return v;
        
    }
};