class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        map<int,int> mp;
        for(int i=0;i<allowed.size();i++)
        {
            mp[allowed[i]]++;
        }
        
        int a=0;
        
        for(int i=0;i<words.size();i++)
        {
            int j;
            for(j=0;j<words[i].length();j++)
            {
                if(mp.find(words[i].at(j))==mp.end())
                {
                    break;
                }
            }
                
            if(j==words[i].length())
            {
               a++;
            }

            
        }
        
        return a;
        
    }
};