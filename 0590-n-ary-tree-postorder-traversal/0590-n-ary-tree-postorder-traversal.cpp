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


void getp(Node*& root,vector<int>& v)
{
    if(root==NULL)
    {
        return;
    }
    
    for(int i=0;i<root->children.size();i++)
    {
           getp(root->children[i],v);
           v.push_back(root->children[i]->val);
    }
    
}



class Solution {
public:
    vector<int> postorder(Node* root) {
        
        vector<int> v;
        
        if(root==NULL)
        {
            return v;
        }
        
        getp(root,v);
        v.push_back(root->val);
        
        return v;
        
        
    }
};