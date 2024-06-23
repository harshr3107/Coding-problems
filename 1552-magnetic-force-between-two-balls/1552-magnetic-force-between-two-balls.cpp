class Solution {
public:
    
    
    bool ispossible(vector<int> pos,int balls,int val)
    {
        sort(pos.begin(),pos.end());
        
        int laspos=pos[0];
        int ballcount=1;
        
        for(int i=0;i<pos.size();i++)
        {
            if(pos[i]-laspos>=val)
            {
                laspos=pos[i];
                ballcount++;
            }
        }
        
        if(ballcount>=balls)
        {
            return true;
        }
        
        return false;
        
        
        
    }
    
    
    
    
    
    int maxDistance(vector<int>& position, int m) {
        
        
        int max=INT_MIN;
        
        for(int i=0;i<position.size();i++)
        {
            
            if(position[i]>max)
            {
                max=position[i];
            }
            
        }
        
        int low=0;
        int high=max;
        int mid;
        int ans=0;
        
         while(high>=low)
        {
             mid=low+(high-low)/2;
            
            if(ispossible(position,m,mid))
            {
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
            
            
        }
        
        
        return ans;
        
        
    }
};