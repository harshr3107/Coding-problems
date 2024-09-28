class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        
        queue<pair<string,int>> q;
        q.push(make_pair(startGene,0));
       
        vector<char> v;
        v.push_back('A');
        v.push_back('C');
        v.push_back('G');
        v.push_back('T');
        
        unordered_map<string,bool> visited;
        visited[startGene]=true;
        
        int ans=0;
        int lastring;
        
        while(!q.empty())
        {
            pair<string,int> tempo = q.front();
            q.pop();
            
            string temp = tempo.first;
            int level = tempo.second;
            ans=level;
            
            if(temp==endGene)
            {
                return ans;
            }
            
            
            
            for(int i=0;i<v.size();i++)
            {
                 for(int j=0;j<temp.length();j++)
                {
                    
                    
                    char c = temp.at(j);
                    temp.at(j)=v[i];
                    
                    
                    if(visited[temp]==true)
                    {
                        
                         temp.at(j)=c;
                        continue;
                        
                    }
                    
                    
                    
                    if(find(bank.begin(),bank.end(),temp)!=bank.end())
                    {
                        visited[temp]=true;
                        q.push(make_pair(temp,level+1));
                    }
                    temp.at(j)=c;
                    
                }
                
            }
            
            
            
            
            
            
            
            
            
        }
        
        
        
        return -1;
        
        
    }
};