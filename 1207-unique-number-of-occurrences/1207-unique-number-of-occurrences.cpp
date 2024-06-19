class Solution {
public:
    
    
    /*int maximumm(vector<int> arr)
    {
        int maxi=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(maxi<arr[i])
            {
                maxi=arr[i];
            }
            
        }
        
        
        return maxi;
    }*/
    
    
    
    bool uniqueOccurrences(vector<int> arr) {
        
    
        vector<bool> visited(arr.size()+1,false);
        vector<int> count(arr.size()+1,0);
        
        
        if(arr.size()==1)
        {
            return true;
        }
        
        int i=0;
        
        while(i<arr.size())
        {
            int a=0;
            
            if(visited[i])
            {
                i++;
                continue;
            }
            
            for(int j=i;j<arr.size();j++)
            {
                if(arr[j]==arr[i])
                {
                    a++;
                    visited[j]=true;
                }
            }
            
            
            if(count[a]==1)
            {
                return false;
            }
            count[a]++;
            i++;
            
        }
        
       
        
        return true;
        
    }
};