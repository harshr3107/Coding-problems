class Solution {
public:
    
    
static bool cmp(pair<char, int>& a, pair<char, int>& b) 
{ 
    return a.second > b.second; 
} 
    
    
string sortbyvalue(map<char,int>& m)
{
        
        vector<pair<char,int>> p;
        
        map<char,int>:: iterator it = m.begin();
        
        while(it!=m.end())
        {
            p.push_back(*it);
            it++;
        }
        
        
        sort(p.begin(),p.end(),cmp);
    
    string ans="";
    
    for(int i=0;i<p.size();i++)
    {
        while(p[i].second>0){
            ans+=p[i].first;
            p[i].second--;
        }
    }
    
   return ans;
        
        
        
    }
    
    
    string frequencySort(string s) {
        
        map<char,int> mp;
        
        for(int i=0;i<s.length();i++)
        {
            mp[s.at(i)]++;
            //cout<<s.at(i)<<" "<<mp[s.at(i)]<<endl;
        }
        
        
        
        
        
        string h = sortbyvalue(mp);
        
        
        return h;
    }
};