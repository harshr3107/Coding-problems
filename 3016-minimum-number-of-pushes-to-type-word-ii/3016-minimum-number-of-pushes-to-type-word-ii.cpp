class Solution {
public:
    
    
    static bool cmp(pair<char,int>& a,pair<char,int>& b)
    {
        return a.second>b.second;
    }
    
    
   int sortmap(unordered_map<char,int>& m)
    {
        
        vector<pair<char,int>> v;
        
        unordered_map<char,int>::iterator it;
       
        for(it=m.begin();it!=m.end();it++)
        {
            pair<char,int> p;
            p.first=it->first;
            p.second=it->second;
            v.push_back(p);
        }
       
       sort(v.begin(),v.end(),cmp);
       
       m.clear();
       map<char,int> mp;
       int push=0;
       int a=0;
       
       for(int i=0;i<v.size();i++)
       {
           if(i<8)
           {
               push+=v[i].second;
               
               
           }else if(i<16)
           {
               push+=2*v[i].second;
               
           }else if(i<24)
           {
               push+=3*v[i].second;
               
           }else{
               
               push+=4*v[i].second;
           }
           
           
       }
       
     
       
        
       return push; 
        
    }
    
    
    
    
    
    int minimumPushes(string word) {
        
        unordered_map<char,int> m;
        
        for(int i=0;i<word.size();i++)
        {
            m[word[i]]++;
        }
        
        return sortmap(m);
        
        
        
       
        
        
        
        
        
        
        
        
       
        
        
        
    }
};