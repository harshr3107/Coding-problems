/*class Solution {
public:
    
    
    int getmaxcount(vector<int>& banned,int n,int maxsum,int cint,vector<vector<int>>& dp)
    {
        //cout<<"i entered here for "<<cint<<" "<<csum<<endl;
        
        if(maxsum<0 || cint>n)
        {
            return 0;
        }
        
        if(dp[cint][maxsum]!=-1)
        {
            return dp[cint][maxsum];
        }
        
        
        
        
        //take
       
        
       
        int take=0;
        
        if(find(banned.begin(),banned.end(),cint)==banned.end() && (maxsum-cint)>=0)
        {
            take=1+getmaxcount(banned,n,maxsum-cint,cint+1,dp);
        }
        
      
        
        //nottake
        int nottake= getmaxcount(banned,n,maxsum,cint+1,dp);
        
       dp[cint][maxsum]=max(take,nottake);
        
        return dp[cint][maxsum];
        
        //return max(take,nottake);
        
    }
    
    
    
    
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
    
        
        //int csum=0;
        int cint=1;
        
        vector<vector<int>> dp(n+1,vector<int>(maxSum,-1));
        
        return getmaxcount(banned,n,maxSum,cint,dp);
        
        
    }
};*/

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Use a set for fast lookup of banned numbers
        unordered_set<int> bannedSet(banned.begin(), banned.end());

        int count = 0;  // Number of valid integers
        int sum = 0;    // Current sum of selected integers

        for (int i = 1; i <= n; ++i) {
            if (bannedSet.find(i) == bannedSet.end() && sum + i <= maxSum) {
                sum += i;
                count++;
            }
        }

        return count;
    }
};



