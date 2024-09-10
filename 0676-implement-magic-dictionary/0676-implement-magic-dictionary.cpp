

class trienode{
    
    public:
    
    char data;
    trienode* children[26];
    bool isterminal;
    
    
    trienode(char a)
    {
        data=a;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        
        isterminal=false;
    }
    
    
    
};

class trie{
  
    public:
    
    
    trienode* root;
    
    
    trie()
    {
        root = new trienode('-');
    }
    
    
    void insertutil(string word,trienode* root)
    {
        if(word.length()==0)
        {
            root->isterminal=true;
            return;
        }
        
        int index = word[0]-'a';
        
        trienode* child;
        
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }else{
            child = new trienode(word[0]);
            root->children[index]=child;
        }
        
        insertutil(word.substr(1),child);
            
        
    }
    
    bool searchutil(string word,int a,trienode* root)
    {
      
        if(word.length()==0)
        {
            if(a==1)
            {
            return root->isterminal;
            }else{
                
              return false;
            }
            
        }
        
        if(a>1)
        {
            return false;
        }
        
        int index = word[0]-'a';
        trienode* child;
        
        for(int i=0;i<26;i++)
        {
            if(root->children[i]!=NULL)
            {
                if(i==index)
                {
                 if(searchutil(word.substr(1),a,root->children[i])==true)
                 {
                     return true;
                 }
                }else{
                    
                 if(searchutil(word.substr(1),a+1,root->children[i])==true)
                 {
                     return true;
                 }
                    
                }
                
                
            }
            
        }
        
        return false;
        
        
        
    }
        
        
   
    
    bool seeifmatch(string word)
    {
        int a=0;
        return searchutil(word,a,root);
        //return true;
    }
    
    
    
    
    void insert(string word)
    {
        insertutil(word,root);
        
    }
    
    
    
};






class MagicDictionary {
public:
    
    
    trie* t;
    
    MagicDictionary() {
        
        t = new trie();
    }
    
    void buildDict(vector<string> dictionary) {
        
        for(int i=0;i<dictionary.size();i++)
        {
            t->insert(dictionary[i]);
        }
            
    }
    
    bool search(string searchWord) {
        
        return t->seeifmatch(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */