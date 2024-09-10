

class trienode{
    
    public:
    char data;
    trienode* children[26];
    bool isterminal=false;
    
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



class WordDictionary {
public:
    
    trienode* root;
    
    
    
    
    
    
    
    
    WordDictionary() {
        
        root = new trienode('-');
        
    }
    
    
    void addwordutil(trienode* root,string word)
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
            child = root->children[index];
        }else{
            
            child = new trienode(word[0]);
            root->children[index]=child;
            
        }
        
        addwordutil(child,word.substr(1));
        
        
    }
    
    bool searchutil(string word,trienode* root)
    {
        //cout<<"i entered here for the word "<<word<<endl;
        
        if(word.length()==0)
        {
            return root->isterminal;
        }
        
        if(word[0]=='.')
        {
           for(int i=0;i<26;i++)
           {
               if(root->children[i]!=NULL)
               {
                   word[0]=root->children[i]->data;
                   if(searchutil(word,root)==true)
                   {
                       return true;   
                   }
               }
               
           }
            
            return false;
            
        }
            
        int index = word[0]-'a';
        
        
        trienode* child;
        
        if(root->children[index]!=NULL)
        {
           child=root->children[index];
        }else{
            return false;
        }
        
        return searchutil(word.substr(1),child);
        
        
    }
    
    
    
    void addWord(string word) {
        
        if(word.find(".")!=string::npos)
        {
            return;
        }
        
        addwordutil(root,word);
    }
    
    bool search(string word) {
        
        return searchutil(word,root);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */