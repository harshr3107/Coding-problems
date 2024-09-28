class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        
        // this i did so that i can hace easy retrival from wordlist
        unordered_set<string> s(wordList.begin(),wordList.end());
        //unordered_map<string,bool> visited;
        
        
        if(s.find(endWord)==s.end())
        {
           
            
            return 0;
        }
        
        //visited[beginWord]=true;
        s.erase(beginWord);
        
       queue<pair<string,int>> q;
        
        q.push(make_pair(beginWord,0));
        
        
        while(!q.empty())
        {
            
            pair<string,int> tempo = q.front();
            q.pop();
            
            
            string temp = tempo.first;
            int level = tempo.second;
            
         //  cout<<"\n\nthe front of the row is "<<temp<<endl;
            
            if(temp==endWord)
            {
                return level+1;
            }
            
            
            
            
            for(char ch='a';ch<='z';ch++)
            {
                
                for(int i=0;i<temp.length();i++)
                {
                    
                    
                    int tp = temp.at(i);
                    temp.at(i)=ch;
                    
                    
                    
                    
                    if(s.find(temp)!=s.end())
                    {
                        s.erase(temp);
                        q.push(make_pair(temp,level+1));
                    }
                    
                    temp.at(i)=tp;
                    
                    
                }
                
               
            }
            
            
            
            
            
        }
        
        
        return 0;
        
        
        
        
        
        
    }
};