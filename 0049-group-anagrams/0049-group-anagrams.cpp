class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<map<char,int>> v(strs.size());
        vector<vector<string>> ans;
        
        for(int i=0;i<strs.size();i++)
        {
            for(int j=0;j<strs[i].length();j++)
            {
                v[i][strs[i][j]]++;
            }
           
        }
        
        
        vector<bool> visited(strs.size(),false);
        vector<string> s;
        
        
        for(int i=0;i<strs.size();i++)
        {
            //cout<<"i came here for i "<<i<<endl;
            
            if(visited[i]==true)
            {
                //cout<<"i came here\n";
                continue;
            }
            //cout<<"i came here for i "<<i<<endl;
            s.push_back(strs[i]);
            visited[i]=true;
              
            for(int j=i+1;j<strs.size();j++)
            {
                if(v[i]==v[j] && visited[j]==false)
                {
                    s.push_back(strs[j]);
                    visited[j]=true;
                }
                
           }
            
            
                if(!s.empty())
                {
                ans.push_back(s);
                }
                s.clear();
       }
        
        
        return ans;
        
    }
};