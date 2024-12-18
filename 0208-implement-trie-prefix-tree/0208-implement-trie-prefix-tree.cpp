
class trienode
{
    public:
    
    
     char data;
     vector<trienode*> children;
     bool isterminal;
    
    
    
    trienode(char ch) {
        
             data=ch;
            
            for(int i=0;i<26;i++)
            {
                children.push_back(NULL);
            }
         
           isterminal=false;
            
            
        }
     

    
};







class Trie {
public:
    
    
     
     trienode* root;
    
    
    
    Trie() {
        
         root = new trienode('/');
        }
    
    
 
        
        
        
    
    
    
    
    void insertword(trienode* root,string word)
    {
        
        if(word.length()==0)
        {
            root->isterminal=true;
            return;
        }
        
        int index = word[0]-'a';
        
        if(root->children[index]==NULL)
        {
            trienode* temp = new trienode(word.at(0));
            root->children[index]=temp;
            root=temp;
            
        }else{
            
            root=root->children[index];
            
        }
        
        insertword(root,word.substr(1));
        
        
        
        
        
    }
    
    
    
    bool searchword(trienode* root,string word)
    {
        
        if(word.length()==0)
        {
            if(root->isterminal)
            {
            return true;
            }
            
            return false;
        }
        
        int index = word.at(0)-'a';
        
        if(root->children[index]==NULL)
        {
            return false;
        }else{
            
            root=root->children[index];
         }
        
        
        
        return searchword(root,word.substr(1));
        
    }
    
    
    
    bool searchp(trienode* root,string word)
    {
        
        if(word.length()==0)
        {
            
            
            return true;
        }
        
        int index = word.at(0)-'a';
        
        if(root->children[index]==NULL)
        {
            return false;
        }else{
            
            root=root->children[index];
         }
        
        
        
        return searchp(root,word.substr(1));
        
    }
    
    
    
    void insert(string word) {
      
       insertword(root,word);
        
        
        
    }
    
    bool search(string word) {
        
       return  searchword(root,word);
        
    }
    
    bool startsWith(string prefix) {
        
        return searchp(root,prefix);
        
        
        
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */