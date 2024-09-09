class trienode
{
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

class Trie {

public:

    /** Initialize your data structure here. */

    trienode* root;

    Trie() {
          root = new trienode('/');

    }

    void insertutil(string word,trienode* root)
    {

        if(word.length()==0)
        {
            root->isterminal=true;
            return;
        }
        
        trienode* child;
        
        //find the index
        int index = word[0]-'a';
        
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
             
            
        }else{
            
            child= new trienode(word[0]);
            root->children[index]=child;
            
            
        }
        
        
        insertutil(word.substr(1),child);
        
    }
    
    bool searchutil(string word,trienode* root)
    {
        

        if(word.length()==0)
        {
            return root->isterminal;
        }
        
        int index = word[0]-'a';
        
        trienode* child;
        
        if(root->children[index]!=NULL)
        {
            child = root->children[index];
            
        }else{
            return false;
        }
        
        return  searchutil(word.substr(1),child);
        
    }

    bool startsutil(string word,trienode* root)
    {
       if(word.length()==0)
        {
            return true;
        }
        
        int index = word[0]-'a';
        
        trienode* child;
        
        if(root->children[index]!=NULL)
        {
            child = root->children[index];
            
        }else{
            return false;
        }
        
        return  startsutil(word.substr(1),child);
        



    }
    
    
    

    /** Inserts a word into the trie. */
    void insert(string word) {

        insertutil(word,root);

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        return  searchutil(word,root);

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        return startsutil(prefix,root);

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */