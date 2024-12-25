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
        //int nottake = INT_MIN;
        
        
        
        
        
         
           
        vtake = curtime*satisfaction[ind]+getmin(satisfaction,ind+1,curtime+1,dp);
        vnottake = getmin(satisfaction,ind+1,curtime,dp);
        
        dp[ind][curtime] = max(vtake,vnottake);
           
        return dp[ind][curtime];
            
        
        /*for(int i=0;i<satisfaction.size();i++)
        { 
            if(visited[i]==true)
            {
                continue;
            }
            
            
            visited[i]=true;
            c++;
            vtake = curtime*satisfaction[i]+getmin(satisfaction,curtime+1,visited,dp,c);
            vnottake = getmin(satisfaction,curtime,visited,dp,c);
            visited[i]=false;
            c--;
            //c--;
           // nottake = getmin(satisfaction,curtime,visited,dp,c);
                
               
        }*/
        
        
        
        
    }
    
    
    
    
    int maxSatisfaction(vector<int>& satisfaction) {
        
        vector<vector<int>> dp(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        vector<bool> visited(satisfaction.size(),false);
        int curtime=1;
        int ind=0;
        return getmin(satisfaction,ind,curtime,dp);
        
    }
};