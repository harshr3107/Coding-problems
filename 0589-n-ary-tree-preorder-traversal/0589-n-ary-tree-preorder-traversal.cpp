/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


void getv(vector<int>& v,Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    for(int i=0;i<root->children.size();i++)
    {
        v.push_back(root->children[i]->val);
        getv(v,root->children[i]);
    }
    
    
    
}






class Solution {
public:
    vector<int> preorder(Node* root) {
        
        vector<int> v;
        if(root==NULL)
        {
            return v;
        }
        
        v.push_back(root->val);
        getv(v,root);
        
        return v;
        
        
        
    }
};