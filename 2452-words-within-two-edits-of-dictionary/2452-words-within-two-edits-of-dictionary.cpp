class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
        vector<string> ans;
        
        
        
        for(int i=0;i<queries.size();i++)
        {
            
            for(int j=0;j<dictionary.size();j++)
            {
                
                int x=0;
                int y=0;
                int h=0;
                
                while(x<dictionary[j].length())
                {
                    if(queries[i].at(x)!=dictionary[j].at(y))
                    {
                        h++;
                    }
                    
                    x++;
                    y++;
                    
                }
                
                if(h<=2)
                {
                    ans.push_back(queries[i]);
                    break;
                }
                
                
            }
            
            
        }
        
        
        return ans;
        
    }
};