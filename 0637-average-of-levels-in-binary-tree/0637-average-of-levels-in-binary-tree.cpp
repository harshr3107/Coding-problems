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
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<double> v;
        double s=0;
        double size=0;
        
        q.push(root);
        q.push(NULL);
        
        
        while(!q.empty())
        {
            
            TreeNode* p = q.front();
            q.pop();
            
            if(p==NULL)
            {
                double a = s/size;
                v.push_back(a);
                s=0;
                size=0;
                
                if(!q.empty())
                {
                    q.push(NULL);
                }
                
                
            }else{
                
                s=s+p->val;
                size++;
                
                if(p->left!=NULL)
                {
                    q.push(p->left);
                }
                if(p->right!=NULL)
                {
                    q.push(p->right);
                }
                
                
                
                
            }
            
            
            
        }
        
        
        return v;
        
        
    }
};