class Solution {
public:
    int characterReplacement(string s, int k) {
        
        
        int low=0;
        int high=0;
        int ans=-1;
        map<char,int> m;
        int curlength;
        int maxi=0;
        
        while(high<s.size())
        {
            m[s.at(high)]++;
            
            curlength = high-low+1;
            maxi = max(maxi, m[s.at(high)]);
            
            if(curlength-maxi>k)
            {
                m[s.at(low)]--;
                low++;
            }
            
             
            
            curlength = high-low+1;
            ans = max(ans,curlength);
            high++;
            
            
        }
        
        
        return ans;
        
    }
};


/*
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0, maxi = 0;
        unordered_map<char,int>mp;
        int ans = -1;
        while(j < n)
        {
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);
            if((j-i+1) - maxi > k){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, (j-i+1));
            j++;   
        }
        return ans;
    }
};*/