class Solution {
public:
    
    
    int getmin(vector<int>& satisfaction,int ind,int curtime,vector<vector<int>>& dp)
    {
        
        //cout<<"value f curtime and c is "<<curtime<<" "<<c<<endl;
        
        if(ind==satisfaction.size())
        {
            return 0;
        }
        
        if(dp[ind][curtime]!=-1)
        {
            return dp[ind][curtime];
        }
        
    
        
        int vtake=INT_MIN;
        int vnottake = INT_MIN;
        
        
        
        
        
         
           
        vtake = curtime*satisfaction[ind]+getmin(satisfaction,ind+1,curtime+1,dp);
        vnottake = getmin(satisfaction,ind+1,curtime,dp);
        
        dp[ind][curtime] = max(vtake,vnottake);
           
        return dp[ind][curtime];
            
       
        
        
    }
    
    
    
    
    int maxSatisfaction(vector<int>& satisfaction) {
        /*
        vector<vector<int>> dp(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        int curtime=1;
        int ind=0;
        return getmin(satisfaction,ind,curtime,dp);
            */
            
             vector<vector<int>> dp(satisfaction.size()+1,vector<int>(satisfaction.size()+2,0));
             sort(satisfaction.begin(),satisfaction.end());
        
            for(int ind=satisfaction.size()-1;ind>=0;ind--)
            {
                
                for(int curtime=ind+1;curtime>=0;curtime--)
                {
                    
                     int vtake=INT_MIN;
                     int vnottake = INT_MIN;
        
                      vtake = (curtime+1)*satisfaction[ind]+dp[ind+1][curtime+1];
                      vnottake =dp[ind+1][curtime];
        
                     dp[ind][curtime] = max(vtake,vnottake);
                    
                    
                    
                }
                
                
            }
            
            return dp[0][0];
        
    }
};